# Use an official C++ runtime as a base image
FROM gcc:latest

# Install necessary packages for building gRPC
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    cmake \
    build-essential \
    autoconf \
    libtool \
    pkg-config \
    libgflags-dev \
    libgtest-dev \
    clang \
    libc++-dev

# Clone the grpc repo and its submodules
RUN git clone --recurse-submodules -b v1.60.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc

# Build and install gRPC and Protocol Buffers
RUN cd grpc && \
    mkdir -p cmake/build && \
    cd cmake/build && \
    cmake -DgRPC_INSTALL=ON \
          -DgRPC_BUILD_TESTS=OFF \
          -DCMAKE_INSTALL_PREFIX=/usr/local \
          ../.. && \
    make -j 4 && \
    make install

RUN find / -name protoc 2>&1

# Copy the current project directory into the container at /app
COPY . /app

# Copy the proto files into the container at /app
RUN rm -rf /app/grpc && mkdir -p /app/grpc
COPY --from=grpc . /app/grpc

# Set the working directory to /app
WORKDIR /app

# Build the project
RUN cmake -DEXECUTABLE_NAME=exchange . --log-level=DEBUG && make

# Run the client/server
CMD ["/app/bin/exchange"]