
#include <iostream>
#include <iomanip>

#include <spdlog/spdlog.h>

#include "core/Logger.h"
#include "order/Order.h"
#include "queue/OrderQueue.h"
#include "Exchange.h"
#include "test/StockGenerator.h"
#include "grpc/ExchangeServiceImpl.h"

std::string serializeTimePoint(const order::time_point_t& time);


void runGRPC() {
    std::string server_address("0.0.0.0:50051");
    ExchangeServiceImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
}



int main()
{
	runGRPC();
    return 0;
}
