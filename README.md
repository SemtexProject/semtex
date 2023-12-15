
# MOUSE (Mason's Online Universal Simulated Exchange)
![image](https://github.com/masonhgn/mouse/assets/73012906/9c1af75e-6596-4bd0-aa5b-f83978d8dcf9 =100x20)


This is a simulation of the financial markets where there are fake tickers, fake prices and fake orders. I made this to try and get some experience with:
- How an orderbook works
- gRPC and C++
- High frequency trading

There are two components of this project:

### Client
- Can place equity orders which route to the server through gRPC
- Handles a portfolio

### Server
- Maintains an orderbook, keeping up to date info on all tickers.
- Matches and executes orders that come from one or more clients
