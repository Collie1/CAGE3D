cmake_minimum_required(VERSION 3.31.2)

project("learningOGL")

file(GLOB_RECURSE "sources" CONFIGURE_DEPENDS
"src/**/*.cpp"
"src/*.cpp"
)

find_package("OpenGL")

add_subdirectory("Libraries/glad")
add_subdirectory("Libraries/glfw")
add_subdirectory("Libraries/glm")

add_subdirectory("Libraries/tiny-image")

add_executable("learningOGL" "${sources}")

target_include_directories("learningOGL" PUBLIC
"Libraries/glad/include"
"Libraries/glfw/include"
"Libraries/glm/"
)

target_link_libraries("learningOGL" PRIVATE
"OpenGL::GL"
"glfw"
"glad"
"glm")


# Copy shaders to the build directory
add_custom_command(
    TARGET "learningOGL"
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/Assets/"
    "$<TARGET_FILE_DIR:learningOGL>/Assets/"
)