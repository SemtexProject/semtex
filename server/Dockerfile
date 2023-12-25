# Dockerfile to build the image for the server

FROM ubuntu:latest

RUN apt-get update && apt-get upgrade

# Install the required packages
RUN apt-get install -y cmake make g++ git

# Copy the source code
COPY . /usr/src/server

# Build the server
WORKDIR /usr/src/server

RUN cmake -DEXECUTABLE_NAME=server . && make

# Run the server
CMD ["./bin/server"]