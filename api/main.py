from fastapi import FastAPI, status
from fastapi.routing import APIRouter
from fastapi.responses import JSONResponse

import os

from models import OrderData
from db.models import Order, User
from exchange import Exchange
from db.session import Session

DEBUG = os.getenv("DEBUG", False)

app = FastAPI(debug=DEBUG)

router = APIRouter(prefix="/api")

@router.post("/submit")
async def submit_order(order: OrderData):
    userObj = User(id=1)
    orderObj = Order(
        userId=1,
        symbol=order.symbol,
        price=order.price,
        quantity=order.quantity,
        side=order.side,
        type=order.type,
        status="OPEN"
    )

    with Session() as session:
        session.add(userObj)
        session.add(orderObj)
        Exchange.add_order(orderObj.id) # Must be scoped to context manager or session will be closed bedore id can be read

        session.commit()


    return JSONResponse(status_code=status.HTTP_201_CREATED, content={"message": "Order submitted successfully"})

app.include_router(router)