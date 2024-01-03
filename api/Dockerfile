FROM ubuntu:latest

RUN apt-get update && apt-get upgrade

# Install required packages
RUN apt-get install -y python3 python3-pip

# Install the required packages for mysqlclient
RUN apt-get install -y pkg-config python3-dev build-essential
RUN apt-get install -y default-libmysqlclient-dev

# Copy the source code
COPY . /usr/src/api

# Set the working directory
WORKDIR /usr/src/api

# Install the required packages
RUN pip3 install -r requirements.txt

# Copy the proto files
COPY --from=grpc . grpc_connect

# Remove the old generated proto files
RUN rm -rf grpc_connect/generated

# Create the directory and __init__.py for the new generated proto files
RUN mkdir -p grpc_connect/generated


# Generate the proto files
RUN python3 -m grpc_tools.protoc \
            -I=grpc_connect/protos \
            --python_out=grpc_connect/generated \
            --grpc_python_out=grpc_connect/generated \
            $(find grpc_connect/protos -name "*.proto")

# Run the API
CMD ["uvicorn", "entry:app" , "--reload", "--host", "0.0.0.0" , "--port" , "8000"]