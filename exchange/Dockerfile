# Dockerfile to build the image for the exchange

FROM ubuntu:latest

RUN apt-get update && apt-get upgrade

# Install the required packages
RUN apt-get install -y cmake make g++ git

# Copy the source code
COPY . /usr/src/exchange

# Build the exchange
WORKDIR /usr/src/exchange

RUN cmake -DEXECUTABLE_NAME=exchange . && make

# Run the exchange
CMD ["./bin/exchange"]