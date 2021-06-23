set(3RDPARTY ${PROJECT_SOURCE_DIR}/3rdparty)

set(INCS
    ${3RDPARTY}/opencv/include/opencv4)

set(LIBS
    ${3RDPARTY}/opencv/lib)

include_directories(${INCS})

link_directories(${LIBS})

# use macro to conveniently build multiple source codes.    
macro(add_example name)
    add_executable(${name} ${name}.cpp)
    #target_include_directories(${name} PRIVATE ${OpenCV_INCLUDE_DIRS})
    target_link_libraries(${name} PRIVATE opencv_world)

    # add test to a virtual project group
    #set_property(TARGET ${name} PROPERTY FOLDER "examples")
endmacro()

add_example(mat)
add_example(read_img)
