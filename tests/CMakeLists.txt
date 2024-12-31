if(TARGET Kuavo4pro)
  set(ROBOT_MODULE_PARAMS "\"Kuavo4pro\"")
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}/loader.in.cpp"
                 "${CMAKE_CURRENT_BINARY_DIR}/Kuavo4pro/loader.cpp")
  add_executable(loader_Kuavo4pro
                 "${CMAKE_CURRENT_BINARY_DIR}/Kuavo4pro/loader.cpp")
  target_link_libraries(loader_Kuavo4pro PUBLIC mc_rtc::mc_rbdyn)
  add_test(NAME loader_Kuavo4pro
           COMMAND loader_Kuavo4pro "$<TARGET_FILE_DIR:Kuavo4pro>")
endif()

if(EXISTS "${PROJECT_BINARY_DIR}/yaml/Kuavo4proYAML.yaml")
  set(ROBOT_MODULE_PARAMS
      "\"json\", \"${PROJECT_BINARY_DIR}/yaml/Kuavo4proYAML.yaml\"")
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}/loader.in.cpp"
                 "${CMAKE_CURRENT_BINARY_DIR}/Kuavo4proYAML/loader.cpp")
  add_executable(loader_Kuavo4proYAML
                 "${CMAKE_CURRENT_BINARY_DIR}/Kuavo4proYAML/loader.cpp")
  target_link_libraries(loader_Kuavo4proYAML PUBLIC mc_rtc::mc_rbdyn)
  add_test(NAME loader_Kuavo4proYAML
           COMMAND loader_Kuavo4proYAML
                   "${MC_ROBOTS_RUNTIME_INSTALL_PREFIX}")
endif()
