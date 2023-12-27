# Simulated Exchange Market Trading and Execution System (SEMTEX)

## Overview

Welcome to the Simulated Exchange Market Trading and Execution System repository! This project aims to provide a comprehensive and dynamic simulated environment for stock market trading and execution. Users can leverage this system for educational purposes, gaining hands-on experience in simulated trading activities.

## Features

- Realistic simulation of market conditions.
- Interactive trading interface offering a web-based client and a low-level gRPC interface for high-frequency trading applications.
- High throughput and reliability packaged wit a robust and scalable architecture.
- Support for multiple trading strategies, including market, limit, stop, and stop-limit orders along with a variety of time-in-force options.


## Getting Started

The SEMTEX system is packaged as a Docker container, which can be easily deployed on any machine with Docker installed. To get started, follow the steps below.

### Prerequisites

- [Download and install Docker](https://docs.docker.com/get-docker/)

### Installation

1. Clone the repository and navigate to the project directory

```sh
git clone https://github.com/masonhgn/semtex.git && cd semtex
```

2. Build and deploy using docker-compose

```sh
docker-compose up -d
```

3. Verify that the project is running (No containers should be in an "Exited" state)

```sh
docker-compose ps --all
```

Note: The project may take a few minutes to start up. If the project is not running, try running the command again.

## Documentation

Extensive documentation for the project is in progress and will be available soon. In the meantime, please refer to the source code for more information.

## License

This project is licensed under the [MIT License](link-to-license).

Happy trading!
