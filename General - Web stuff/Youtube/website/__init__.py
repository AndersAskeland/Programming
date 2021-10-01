""" A way to initilize components """
from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_bcrypt import Bcrypt
from flask_login import LoginManager


app = Flask(__name__) # Refers to app.py

""" Configs """
## Make secret key using secrets module and secret.token_hex(n)
app.config["SECRET_KEY"] = "2c894d73af3c06530dae54b3f774b707"
## Configure SQL database
app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///site.db"

""" Database using SQLAlchemy """
# Initiate to db?
db = SQLAlchemy(app)

bcrypt = Bcrypt(app)
login_manager = LoginManager(app)
login_manager.login_view = 'login'


from website import routes
