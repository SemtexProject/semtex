from pydantic import BaseModel

class OrderData(BaseModel):
    symbol: str
    price: float
    quantity: int
    side: str
    type: str