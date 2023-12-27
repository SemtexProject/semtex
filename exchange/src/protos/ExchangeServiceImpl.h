#pragma once

#include <grpc++/grpc++.h>
#include "order.pb.h"
#include "order.grpc.pb.h"
#include "Exchange.h"

using grpc::ServerContext;
using grpc::Status;
using exchange::Order;
using exchange::SubmitOrderResponse;
using exchange::ExchangeService;

class ExchangeServiceImpl final : public exchange::ExchangeService::Service {
    grpc::Status SubmitOrder(grpc::ServerContext* context, const exchange::Order* grpcOrder, exchange::SubmitOrderResponse* response) override {
        // Convert the gRPC Order to your internal Order class
        order::Order internalOrder = ConvertToInternalOrder(*grpcOrder);

        // Obtain an instance of your Exchange and submit the order
        Exchange &ex = Exchange::getInstance();
        ex.submit(internalOrder);

        // Set response status
        response->set_status("Order submitted successfully");
        return grpc::Status::OK;
    }

private:
    order::Order ConvertToInternalOrder(const exchange::Order& grpcOrder) {
        // Conversion logic from gRPC Order to your internal Order class
        // Adjust field names and types as necessary
        return order::Order(
            grpcOrder.id(),
            static_cast<order::quantity_t>(grpcOrder.quantity()),
            grpcOrder.price(),
            static_cast<order::side_t>(grpcOrder.side()), // Assuming side is an enum/int in gRPC
            static_cast<order::type_t>(grpcOrder.type()), // Same assumption as above
            grpcOrder.symbol(),
            static_cast<order::duration_t>(grpcOrder.duration()) // Adjust as per your duration type
        );
    }
};
