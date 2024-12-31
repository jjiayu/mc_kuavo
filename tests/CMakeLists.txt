if(TARGET KuavoRobotModule)
  set(ROBOT_MODULE_PARAMS "\"KuavoRobotModule\"")
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}/loader.in.cpp"
                 "${CMAKE_CURRENT_BINARY_DIR}/KuavoRobotModule/loader.cpp")
  add_executable(loader_KuavoRobotModule
                 "${CMAKE_CURRENT_BINARY_DIR}/KuavoRobotModule/loader.cpp")
  target_link_libraries(loader_KuavoRobotModule PUBLIC mc_rtc::mc_rbdyn)
  add_test(NAME loader_KuavoRobotModule
           COMMAND loader_KuavoRobotModule "$<TARGET_FILE_DIR:KuavoRobotModule>")
endif()

if(EXISTS "${PROJECT_BINARY_DIR}/yaml/KuavoRobotModuleYAML.yaml")
  set(ROBOT_MODULE_PARAMS
      "\"json\", \"${PROJECT_BINARY_DIR}/yaml/KuavoRobotModuleYAML.yaml\"")
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}/loader.in.cpp"
                 "${CMAKE_CURRENT_BINARY_DIR}/KuavoRobotModuleYAML/loader.cpp")
  add_executable(loader_KuavoRobotModuleYAML
                 "${CMAKE_CURRENT_BINARY_DIR}/KuavoRobotModuleYAML/loader.cpp")
  target_link_libraries(loader_KuavoRobotModuleYAML PUBLIC mc_rtc::mc_rbdyn)
  add_test(NAME loader_KuavoRobotModuleYAML
           COMMAND loader_KuavoRobotModuleYAML
                   "${MC_ROBOTS_RUNTIME_INSTALL_PREFIX}")
endif()
