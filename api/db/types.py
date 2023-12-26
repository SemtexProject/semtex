from sqlalchemy import Enum


class OrderSide(Enum):
    BUY = 'BUY'
    SELL = 'SELL'

class OrderType(Enum):
    MARKET = 'MARKET'
    LIMIT = 'LIMIT'
    STOP = 'STOP'

class OrderStatus(Enum):
    OPEN = 'OPEN'
    FILLED = 'FILLED'
    CANCELED = 'CANCELED'
    REJECTED = 'REJECTED'
    EXPIRED = 'EXPIRED'
    PARTIALLY_FILLED = 'PARTIALLY_FILLED'
    PENDING_CANCEL = 'PENDING_CANCEL'