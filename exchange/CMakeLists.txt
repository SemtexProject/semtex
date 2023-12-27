cmake_minimum_required(VERSION 3.12)
project(Mouse)

set(CMAKE_CXX_STANDARD 20)

# Program options
option(EXECUTABLE_NAME "Name of the executable" "Mouse")

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Find Protobuf and gRPC
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

# Generate gRPC and Protobuf sources
set(PROTO_SRC_DIR ${CMAKE_CURRENT_BINARY_DIR}/proto_src)
file(MAKE_DIRECTORY ${PROTO_SRC_DIR})
include_directories(${PROTO_SRC_DIR})

set(PROTO_FILE ${CMAKE_SOURCE_DIR}/protos/order.proto)
set(GENERATED_SOURCES
  ${PROTO_SRC_DIR}/order.pb.cc
  ${PROTO_SRC_DIR}/order.pb.h
  ${PROTO_SRC_DIR}/order.grpc.pb.cc
  ${PROTO_SRC_DIR}/order.grpc.pb.h
)

add_custom_command(
  OUTPUT ${GENERATED_SOURCES}
  COMMAND ${Protobuf_PROTOC_EXECUTABLE}
  ARGS --grpc_out=${PROTO_SRC_DIR}
       --cpp_out=${PROTO_SRC_DIR}
       -I ${CMAKE_SOURCE_DIR}/protos
       --plugin=protoc-gen-grpc=${gRPC_CPP_PLUGIN_EXECUTABLE}
       ${PROTO_FILE}
  DEPENDS ${PROTO_FILE}
)

# Add external libraries using FetchContent
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
FetchContent_MakeAvailable(spdlog)

# Find all source files including the generated gRPC and Protobuf files
file(GLOB_RECURSE SOURCES "src/*.cpp" ${GENERATED_SOURCES})

# Add the executable
add_executable(Mouse ${SOURCES})

# Add header files
target_include_directories(Mouse PUBLIC src ${PROTO_SRC_DIR})

# Link libraries including gRPC, Protobuf, and SPDLog
target_link_libraries(Mouse PUBLIC
  spdlog::spdlog
  gRPC::grpc++
  gRPC::grpc++_reflection
  protobuf::libprotobuf
  absl::base
  absl::strings
  absl::synchronization
)

# Set executable name
set_target_properties(Mouse PROPERTIES OUTPUT_NAME ${EXECUTABLE_NAME})
