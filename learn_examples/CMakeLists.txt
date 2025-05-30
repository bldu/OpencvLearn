

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


endforeach()
