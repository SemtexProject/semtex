from sqlalchemy.orm import sessionmaker

from db.engine import engine


Session = sessionmaker(engine)