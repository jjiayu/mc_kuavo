#pragma once

#include <mc_rbdyn/RobotModule.h>

#include <mc_robots/api.h>

namespace mc_robots
{

struct MC_ROBOTS_DLLAPI Kuavo4pro : public mc_rbdyn::RobotModule
{
public:
  Kuavo4pro();
};

} // namespace mc_robots

//Previous way, now abandoned
// extern "C"
// {
//   ROBOT_MODULE_API void MC_RTC_ROBOT_MODULE(std::vector<std::string> & names)
//   {
//     // Names of the robots exported by this module
//     names = {"Kuavo4pro"};
//   }
//   ROBOT_MODULE_API void destroy(mc_rbdyn::RobotModule * ptr)
//   {
//     delete ptr;
//   }
//   ROBOT_MODULE_API mc_rbdyn::RobotModule * create(const std::string & name)
//   {
//     // At this point name must be one of the supported robots
//     if(name == "Kuavo4pro")
//     { 
//       return new mc_robots::Kuavo4pro(); 
//     }
//     else
//     {
//       mc_rtc::log::error("Kuavo4pro module Cannot create an object of type {}", name);
//       return nullptr;
//     }
//   }
// }