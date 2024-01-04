from sqlalchemy import create_engine

connection_string = 'mysql+pymysql://root:root@mysql:3306/test'

engine = create_engine(connection_string, echo=True)