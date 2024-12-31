#include "Kuavo4pro.h"

#include <RBDyn/parsers/urdf.h>

#include <boost/filesystem.hpp>

namespace bfs = boost::filesystem;

namespace
{

// This is set by CMake, see CMakeLists.txt
static const std::string MC_KUAVO4PRO_DESCRIPTION_PATH = "@MC_KUAVO4PRO_DESCRIPTION_PATH@";

} // namespace

namespace mc_robots
{

Kuavo4pro::Kuavo4pro() : mc_rbdyn::RobotModule(MC_KUAVO4PRO_DESCRIPTION_PATH, "kuavo4pro") //kuavo4pro is the urdf file name

{
  // True if the robot has a fixed base, false otherwise
  bool fixed = false;
  // Makes all the basic initialization that can be done from an URDF file
  init(rbd::parsers::from_urdf_file(urdf_path, fixed));

  // Automatically load the convex hulls associated to each body
  std::string convexPath = path + "/convex/" + name + "/";
  bfs::path p(convexPath);
  if(bfs::exists(p) && bfs::is_directory(p))
  {
    std::vector<bfs::path> files;
    std::copy(bfs::directory_iterator(p), bfs::directory_iterator(), std::back_inserter(files));
    for(const bfs::path & file : files)
    {
      size_t off = file.filename().string().rfind("-ch.txt");
      if(off != std::string::npos)
      {
        std::string name = file.filename().string();
        name.replace(off, 7, "");
        _convexHull[name] = std::pair<std::string, std::string>(name, file.string());
      }
    }
  }

  // Define some force sensors
  _forceSensors.push_back(mc_rbdyn::ForceSensor("RightFootForceSensor", "R_ANKLE_P_S", sva::PTransformd::Identity()));
  _forceSensors.push_back(mc_rbdyn::ForceSensor("LeftFootForceSensor", "L_ANKLE_P_S", sva::PTransformd::Identity()));
  _forceSensors.push_back(mc_rbdyn::ForceSensor("RightHandForceSensor", "R_WRIST_Y_S", sva::PTransformd::Identity()));
  _forceSensors.push_back(mc_rbdyn::ForceSensor("LeftHandForceSensor", "L_WRIST_Y_S", sva::PTransformd::Identity()));

  // Define body sensors
  _bodySensors.emplace_back("Accelerometer", "PELVIS_S", sva::PTransformd(Eigen::Vector3d(-0.0325, 0, 0.1095)));
  _bodySensors.emplace_back("FloatingBase", "PELVIS_S", sva::PTransformd::Identity());

  // Define a minimal set of self-collisions
  // _minimalSelfCollisions = {
  //     {"WAIST_R_S", "L_SHOULDER_Y_S", 0.02, 0.001, 0.}, {"WAIST_R_S", "R_SHOULDER_Y_S", 0.02, 0.001, 0.},
  //     {"PELVIS_S", "R_ELBOW_P_S", 0.05, 0.001, 0.},     {"PELVIS_S", "L_ELBOW_P_S", 0.05, 0.001, 0.},
  //     {"R_WRIST_Y_S", "R_HIP_Y_S", 0.05, 0.025, 0.},    {"L_WRIST_Y_S", "L_HIP_Y_S", 0.05, 0.025, 0.}};
  // _commonSelfCollisions = _minimalSelfCollisions;

  // Define simple grippers
  // _grippers = {{"l_gripper", {"L_UTHUMB"}, true}, {"r_gripper", {"R_UTHUMB"}, false}};

  // Default configuration of the floating base
  _default_attitude = {{1., 0., 0., 0., 0., 0., 0.888}};

  // Default joint configuration, if a joint is omitted the configuration is 0 or the middle point of the limit range if
  // 0 is not a valid configuration
  // Add default join configuration as:
  // _stance["joint_name"] = {-0.33};
}

} // namespace mc_robots

#include <mc_rbdyn/RobotModuleMacros.h>

ROBOT_MODULE_DEFAULT_CONSTRUCTOR("Kuavo4pro", mc_robots::Kuavo4pro)
