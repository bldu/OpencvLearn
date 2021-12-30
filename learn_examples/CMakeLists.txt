set(3RDPARTY ${PROJECT_SOURCE_DIR}/thirdparty)

set(INCS
    ${3RDPARTY}/opencv/include/opencv4)

IF (WIN32)
    MESSAGE(STATUS "windows")
ELSEIF (APPLE)
    MESSAGE(STATUS "Apple systems.")
    set(LIBS
            ${3RDPARTY}/opencv/lib)
ELSEIF (UNIX)
    MESSAGE(STATUS "UNIX-like OS's.")
    set(LIBS
            ${3RDPARTY}/opencv/lib64)
ENDIF ()



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
add_example(simple_animation)
add_example(mouse_line)
add_example(mouse_rectangle)
