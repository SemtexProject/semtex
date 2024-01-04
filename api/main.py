from fastapi import FastAPI, status
from fastapi.routing import APIRouter
from fastapi.responses import JSONResponse

import os

from models import OrderRequest, OrderDto, OrderResponse
from db.models import Order, User
from exchange import Exchange
from db.session import Session

DEBUG = os.getenv("DEBUG", False)

app = FastAPI(debug=DEBUG)

router = APIRouter(prefix="/api")

@router.post("/submit")
async def submit_order(order: OrderRequest):
    orderObj = Order(
        userId=1,
        symbol=order.symbol,
        price=order.price,
        quantity=order.quantity,
        side=order.side,
        type=order.type,
        status="OPEN"
    )

    user = User(orders=[orderObj])

    with Session() as session:
        session.add(orderObj)
        session.add(user)

        session.flush() # Update orderObj with id
        session.refresh(orderObj)

        orderDto = OrderDto(
            id=orderObj.id,
            symbol=orderObj.symbol,
            price=orderObj.price,
            quantity=orderObj.quantity,
            side=orderObj.side,
            type=orderObj.type,
            status=orderObj.status
        )

        Exchange.add_order(orderDto) # Must be scoped to context manager or session will be closed bedore id can be read

        session.commit() # Save database changes

    return JSONResponse(status_code=status.HTTP_201_CREATED, content={"message": "Order submitted successfully"})

app.include_router(router)