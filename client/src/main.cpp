#include <iostream>
#include "ExchangeClient.h"
#include <grpcpp/grpcpp.h>
#include "protos/order.pb.h"
#include "protos/order.grpc.pb.h"

using exchange::Order;

int main() {
    ExchangeClient client(grpc::CreateChannel(
        "exchange-server:50051", grpc::InsecureChannelCredentials()));

    Order order;
    order.set_id(1); // Set appropriate values
    order.set_quantity(10);
    order.set_price(100.0);
    order.set_symbol("AAPL");
    order.set_side(2);

    // ... set other order fields

    client.SubmitOrder(order);

    return 0;
}