cmake_minimum_required(VERSION 3.12)
project(Mouse)

set(CMAKE_CXX_STANDARD 20)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})


# Add external libraries

include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

# Add SPDLog
set(spdlog_GIT_REPOSITORY "https://github.com/gabime/spdlog.git")
set(spdlog_GIT_TAG "v1.12.0")
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY ${spdlog_GIT_REPOSITORY}
        GIT_TAG ${spdlog_GIT_TAG}
)

# Add ImGui
# set(imgui_GIT_REPOSITORY "https://github.com/ocornut/imgui.git")
# set(imgui_VERSION "v1.90")
# FetchContent_Declare(
#   imgui
#   URL "https://github.com/ocornut/imgui/archive/${imgui_VERSION}.zip"
# )


# Make libraries available to link
FetchContent_MakeAvailable(spdlog)# imgui)


# Find all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add the executable
add_executable(Mouse ${SOURCES})

# Add header files
target_include_directories(Mouse PUBLIC src)

# Link libraries
target_link_libraries(Mouse PUBLIC spdlog::spdlog)
