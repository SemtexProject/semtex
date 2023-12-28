from datetime import datetime
import uuid
from typing import List

from sqlalchemy import String, ForeignKey

from sqlalchemy.orm import mapped_column
from sqlalchemy.orm import DeclarativeBase
from sqlalchemy.orm import Mapped
from sqlalchemy.orm import relationship


from sqlalchemy.sql import func
from sqlalchemy.types import DateTime

from db.types import *

class Base(DeclarativeBase):
    pass


class Order(Base):
    __tablename__ = 'orders'

    id: Mapped[int] = mapped_column(primary_key=True, autoincrement=True)
    userId: Mapped[int] = mapped_column(ForeignKey('users.id'), nullable=False)

    symbol: Mapped[str] = mapped_column(String(10), nullable=False)
    price: Mapped[float] = mapped_column(nullable=False)
    quantity: Mapped[int] = mapped_column(nullable=False)
    side: Mapped[OrderSide] = mapped_column(String(4), nullable=False)
    type: Mapped[OrderType] = mapped_column(String(16), nullable=False)
    status: Mapped[OrderStatus] = mapped_column(String(20), nullable=False)

    created_at: Mapped[datetime] = mapped_column(DateTime, nullable=False, default=func.now())
    updated_at: Mapped[datetime] = mapped_column(DateTime, nullable=False, default=func.now(), onupdate=func.now())

class User(Base):
    __tablename__ = 'users'

    id: Mapped[int] = mapped_column(primary_key=True, autoincrement=True)
    orders: Mapped[List[Order]] = relationship("Order", backref="user")

    created_at: Mapped[datetime] = mapped_column(DateTime, nullable=False, default=func.now())
    updated_at: Mapped[datetime] = mapped_column(DateTime, nullable=False, default=func.now(), onupdate=func.now())



