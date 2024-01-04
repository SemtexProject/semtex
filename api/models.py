from pydantic import BaseModel

class OrderRequest(BaseModel):
    symbol: str
    price: float
    quantity: int
    side: str
    type: str

class OrderDto(BaseModel):
    id: int
    symbol: str
    price: float
    quantity: int
    side: str
    type: str
    status: str

class OrderResponse(OrderDto):
    pass