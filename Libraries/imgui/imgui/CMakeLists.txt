cmake_minimum_required(VERSION 3.31.2)

project("imgui")

file(GLOB_RECURSE "IMGUI_SRCS" CONFIGURE_DEPENDS "./*.cpp")

add_library("imgui" ${IMGUI_SRCS})