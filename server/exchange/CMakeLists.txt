cmake_minimum_required(VERSION 3.12)
project(MouseServer)

set(CMAKE_CXX_STANDARD 20)

# Find Protobuf and gRPC
find_package(Protobuf REQUIRED CONFIG)
find_package(gRPC REQUIRED)

find_program(Protobuf_PROTOC_EXECUTABLE NAMES protoc)
find_program(gRPC_CPP_PLUGIN_EXECUTABLE NAMES grpc_cpp_plugin)

# Set variables for source generation
set(PROTO_SRC_DIR ${CMAKE_SOURCE_DIR}/src/protos)
set(PROTO_FILE ${PROTO_SRC_DIR}/order.proto)
set(PROTO_SRC "${PROTO_SRC_DIR}/order.pb.cc")
set(PROTO_HDR "${PROTO_SRC_DIR}/order.pb.h")
set(GRPC_SRC "${PROTO_SRC_DIR}/order.grpc.pb.cc")
set(GRPC_HDR "${PROTO_SRC_DIR}/order.grpc.pb.h")

message("PROTO SOURCE DIR: ${PROTO_SRC_DIR}")
message("PROTO FILE: ${PROTO_FILE}")
message("generated: ${PROTO_SRC} ${PROTO_HDR} ${GRPC_SRC} ${GRPC_HDR}")
# Custom command to generate protobuf and gRPC sources
add_custom_command(
  OUTPUT "${PROTO_SRC}" "${PROTO_HDR}" "${GRPC_SRC}" "${GRPC_HDR}"
  COMMAND ${Protobuf_PROTOC_EXECUTABLE}
    ARGS --grpc_out="${PROTO_SRC_DIR}"
         --cpp_out="${PROTO_SRC_DIR}"
         -I "${PROTO_SRC_DIR}"
         --plugin=protoc-gen-grpc="${gRPC_CPP_PLUGIN_EXECUTABLE}"
         "${PROTO_FILE}"
  DEPENDS "${PROTO_FILE}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")
include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${CMAKE_SOURCE_DIR}/src")
include_directories("${PROTO_SRC_DIR}")
#message("SOURCE DIRECTORY: ${CMAKE_SOURCE_DIR}")



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



# Add the executable
add_executable(MouseServer 
    src/main.cpp
    src/order/Order.cpp
    src/core/Logger.cpp
    ${PROTO_SRC}
    ${PROTO_HDR}
    ${GRPC_SRC}
    ${GRPC_HDR}
)

# Link libraries
target_link_libraries(MouseServer 
    ${Protobuf_LIBRARIES}
    spdlog::spdlog
    gRPC::grpc++ 
    gRPC::grpc++_reflection
    # Other libraries you might need
)

# Set executable name
set_target_properties(MouseServer PROPERTIES OUTPUT_NAME ${EXECUTABLE_NAME})
