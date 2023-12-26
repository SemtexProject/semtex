from abc import ABC

import network

class Exchange(ABC):

    @staticmethod
    def add_order(order_id):
        network.emit('exchange.tasks.add_order', order_id)