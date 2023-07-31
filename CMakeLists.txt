cmake_minimum_required(VERSION 3.10)

project(GlfwTemplate)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/glm)
add_subdirectory(dependencies/glad41core)
add_subdirectory(dependencies/spdlog)
add_subdirectory(dependencies/stb)

add_executable(GlfwTemplate "src/main.cpp")

target_link_libraries(GlfwTemplate PRIVATE glfw glm spdlog::spdlog glad41core stb::image)
