
![mouse](https://github.com/masonhgn/mouse/assets/73012906/7060bd77-d515-4275-8ee9-47db2c6138af)


# The MOUSE Exchange
My very own simulated stock exchange!


## High Level Overview:

There are two main components of this project:

### Client
- Can place equity orders which route to the server through gRPC
- Handles a portfolio

### Server
- Maintains an orderbook, keeping up to date info on all tickers.
- Matches and executes orders that come from one or more clients.

To manage orders, we must have a...
#### Central Limit Order Book (CLOB)
This will be the orderbook maintained by the server, and it will be responsible for handling all orders.

And to actually listen for orders from clients, we use gRPC.




## In depth Overview:

### Client
//TODO write client components

### Server
- (Order.cpp): Acts as a single order (parent class)
- (LimitOrder.cpp, MarketOrder.cpp): Children of the Order class, these act as specific orders which the Orderbook will interact with in various ways.
- (Orderbook.cpp)
