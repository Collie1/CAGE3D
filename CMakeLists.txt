cmake_minimum_required(VERSION 3.31.2)

project("CAGE3D")

file(GLOB_RECURSE "sources" CONFIGURE_DEPENDS
"src/**/*.cpp"
"src/*.cpp"
)

find_package("OpenGL")

add_subdirectory("Libraries/glad")
add_subdirectory("Libraries/glfw")
add_subdirectory("Libraries/glm")

add_executable("CAGE3D" "${sources}")

target_include_directories("CAGE3D" PUBLIC
"Libraries/glad/include"
"Libraries/glfw/include" 
"Libraries/glm/"
"Libraries/tiny-image/include"
"Libraries/stb"
"LIbraries/imgui"
)

target_link_libraries("CAGE3D" PRIVATE
"OpenGL::GL"
"glfw"
"glad"
"glm"
"imgui"
)


# Copy shaders to the build directory
add_custom_command(
    TARGET "CAGE3D"
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/Assets/"
    "$<TARGET_FILE_DIR:CAGE3D>/Assets/"
)