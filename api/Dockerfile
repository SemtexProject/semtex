FROM ubuntu:latest

RUN apt-get update && apt-get upgrade

# Install required packages
RUN apt-get install -y python3 python3-pip redis-server

# Install the required packages for mysqlclient
RUN apt-get install -y pkg-config python3-dev build-essential
RUN apt-get install -y default-libmysqlclient-dev

# Copy the source code
COPY . /usr/src/api

# Set the working directory
WORKDIR /usr/src/api

# Install the required packages
RUN pip3 install -r requirements.txt

# Check for database migrations and run them if needed

# Run the API
CMD ["uvicorn", "entry:app" , "--reload", "--host", "0.0.0.0" , "--port" , "8000"]