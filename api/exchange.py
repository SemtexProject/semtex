from abc import ABC

from grpc_connect.generated.order_pb2 import Order as ExchangeOrder # type: ignore
from grpc_connect.generated.order_pb2_grpc import ExchangeService, ExchangeServiceStub # type: ignore
import grpc

from models import OrderDto

class Exchange(ABC):

    @staticmethod
    def add_order(order: OrderDto):
        with grpc.insecure_channel('exchange:50051') as channel:
            stub = ExchangeServiceStub(channel)
            response = stub.SubmitOrder(ExchangeOrder(
                id=order.id,
                symbol=order.symbol,
                price=order.price,
                quantity=order.quantity,
                side=0,
                type=0,
            ))

            return response.status