from typing import Any

from redis import Redis
from rq import Queue

redis = Redis(host='redis', port=6379)
redis_queue = Queue(connection=redis)

def emit(event: str, data: Any):
    redis_queue.enqueue(event, data)