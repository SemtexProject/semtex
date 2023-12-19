#ifndef ORDER_H
#define ORDER_H

#include <chrono>
#include <string>

enum Duration { day, goodTillCanceled };
enum OrderSide { buy, sell };

class Order {
public:
    virtual ~Order() {}

    //accessors
    float getQuantity() const;
    OrderSide getOrderSide() const;
    long getId() const;
    std::string getSymbol() const;
    Duration getDuration() const;
    std::chrono::steady_clock::time_point getTimeStamp() const;


    //mutators
    bool setQuantity(const float &q);
    bool setSymbol(const std::string &s);
    bool setOrderSide(const OrderSide &s);
    bool setDuration(const Duration& d);

protected:
    //factory pattern, cannot instantiate Order class itself
    Order(
        long orderId, 
        float orderQuantity, 
        OrderSide orderSide,
        std::string orderSymbol,
        Duration orderDuration
    );

private:
    std::chrono::steady_clock::time_point timestamp;
    long id;
    float quantity;
    OrderSide side;
    std::string symbol;
    Duration duration;

};

#endif 




