

# 自动遍历目录下的所有.cpp文件
file(GLOB example_sources "*.cpp")

# 为每个案例生成独立可执行文件
foreach(source_file ${example_sources})
    # 提取不带扩展名的文件名
    get_filename_component(example_name ${source_file} NAME_WE)

    # 创建可执行文件
    add_executable(${example_name} ${source_file})

    # 链接OpenCV库
    target_link_libraries(${example_name} PRIVATE ${OpenCV_LIBS})

    # 设置头文件包含路径
    target_include_directories(${example_name} PRIVATE ${OpenCV_INCLUDE_DIRS})

    # # 设置输出目录（可选）
    # set_target_properties(${example_name} PROPERTIES
    #     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    # )
    if (WIN32)
    add_custom_command(TARGET ${example_name} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${example_name}> $<TARGET_FILE_DIR:${example_name}>
    COMMAND_EXPAND_LISTS
    )
    endif()


endforeach()

# if (WIN32)
# file(GLOB OPENCV_DLLS "${OpenCV_DIR}/x64/vc16/bin/*.dll")
# message(STATUS "OPENCV_DLLS: ${OPENCV_DLLS}")
# message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
# file(COPY ${OPENCV_DLLS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
# endif()
