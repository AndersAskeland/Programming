import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__) # __name__ means application.py

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


# Index
@app.route("/")
@login_required
def index():
    # Variables
    stocks = db.execute("SELECT * FROM stocks WHERE id = :id", id=session["user_id"])
    total = 0
    
    # Update sell prices
    for i, row in enumerate(stocks):
        sell_price = lookup(row['stockSymbol'])
    
        # Update with sell price
        db.execute("UPDATE stocks SET sellPrice = :sell_price WHERE id = :id AND stockSymbol = :stockSymbol", id=session["user_id"], sell_price=sell_price['price'], stockSymbol=row['stockSymbol'])
        
        # Update total
        cost = db.execute("SELECT sellPrice, shares FROM stocks WHERE id = :id", id=session["user_id"])
        total += (cost[i]['sellPrice'] * cost[i]['shares'])

    # New updated stocks
    stocks_new = db.execute("SELECT * FROM stocks WHERE id = :id AND shares > 0", id=session["user_id"])
    cash = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])

    # Return template
    return render_template("index.html", stocks_new=stocks_new, total=total, cash=cash[0]["cash"])


# change password
@app.route("/password", methods=["GET", "POST"])
@login_required
def password():
    # POST requests
    if request.method == "POST":
        # Ensure old_password was submitted
        if not request.form.get("old_password"):
            return apology("must provide old password", 403)

        # Ensure password was submitted
        elif not request.form.get("new_password"):
            return apology("must provide new password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE id = :id", id=session["user_id"])

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("old_password")):
            return apology("Your old password is not correct", 403)

        # Revieve hased password
        pass_hash=generate_password_hash(request.form.get("new_password"))

        # Write into DB
        db.execute("UPDATE users SET hash = :hash WHERE id = :id", hash=pass_hash, id=session["user_id"])
        
        return redirect("/")
    else:
        return render_template("password.html")

# Buy
@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    # POST requests
    if request.method == "POST":
        # Stock lookup
        stock = lookup(request.form.get("stock"))

        # Error checking
        if stock is None:
            return apology("That is not a real stock")
        # Stock exist
        else:
            # Variables
            symbol = db.execute("SELECT stockSymbol FROM stocks WHERE stockSymbol = :stockSymbol AND id = :id", stockSymbol=stock["symbol"], id=session["user_id"])
            cash = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])
            n = float(request.form.get("shares"))
            price = float(stock["price"]) * float(n)

            # Check
            if price > cash[0]['cash']:
                return apology("You do not have enought cash")
            else:
                # Already in database
                if len(symbol) > 0:
                    db.execute("UPDATE stocks SET buyPrice = ((((buyPrice * shares) + (:buyPrice * :shares))/ (shares + :shares)) / 2), shares = (shares + :shares) WHERE stockSymbol = :stockSymbol AND id = :id", buyPrice=stock["price"], stockSymbol=stock["symbol"], shares=request.form.get("shares"), id=session["user_id"])
                    db.execute("UPDATE users SET cash = :cash WHERE id = :id", cash=(cash[0]['cash'] - price), id=session["user_id"])
                    
                    # Write to history
                    db.execute("INSERT INTO history (stockSymbol, name, shares, price, id) VALUES (:stockSymbol, :name, :shares, :price, :id)", stockSymbol=stock["symbol"], name=stock["name"], shares=request.form.get("shares"), price=stock["price"], id=session["user_id"])
                    
                    # Redirect to index
                    return redirect("/")

                # Not in database
                else:
                    # Write to db
                    db.execute("INSERT INTO stocks (stockSymbol, name, buyPrice, shares, id) VALUES (?, ?, ?, ?, ?)", stock["symbol"], stock["name"], stock["price"], request.form.get("shares"), session["user_id"])
                    
                    # Updage cash balance
                    db.execute("UPDATE users SET cash = :cash WHERE id = :id", cash=(cash[0]['cash'] - price), id=session["user_id"])

                    # Write to history
                    db.execute("INSERT INTO history (stockSymbol, name, shares, price, id) VALUES (:stockSymbol, :name, :shares, :price, :id)", stockSymbol=stock["symbol"], name=stock["name"], shares=request.form.get("shares"), price=stock["price"], id=session["user_id"])

                    # Redirect to index
                    return redirect("/")

    # GET requests
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    # Variables
    history = db.execute("SELECT * FROM history WHERE id = :id", id=session["user_id"])

    # Return template
    return render_template("history.html", history=history)


# Login
@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")





# Logout
@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")





# Get a stock quote
@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    # POST
    if request.method == "POST": # Remember to check if valid
        # Lookup
        quote = lookup(request.form.get("stock"))
        
        # Error checking
        if quote is None:
            return apology("That is not a real stock")
        else:
            return render_template("quoted.html", quote=quote)

    # GET
    else:
        return render_template("quote.html")




# Regitration page
@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST": # when you hit register
        ### Error checking (backend) ### 
        # Valid input
        if not request.form.get("username") or not request.form.get("password"):
            return apology("Wrong information!")
        
        # Check dupliate usernames
        result = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))
        if len(result) != 0:
            return apology("User already exist")



        ### Write into database ###
        # Recieve username
        username=request.form.get("username")

        # Revieve hased password
        pass_hash=generate_password_hash(request.form.get("password"))

        # Write into DB
        db.execute("INSERT INTO users (username, hash) VALUES (?,?)", username, pass_hash)

        # Return to login after successful registration
        return redirect("/login")

    else: # Also check session - Possible in GET
        return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    # POST requests
    if request.method == "POST":
        # Retrive input
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

       
        # Find sell price and stocks
        sell_price = db.execute("SELECT shares, sellPrice FROM stocks WHERE id = :id AND stockSymbol=:stock", id=session["user_id"], stock=symbol)

        # Error - If below or above total stock
        if int(shares) > int(sell_price[0]["shares"]):
            return apology("You dont have that many shares!")

        # Update cash and stock
        db.execute("UPDATE stocks SET shares = (shares - :shares) WHERE id = :id AND stockSymbol = :stockSymbol", shares=shares, id=session["user_id"], stockSymbol=symbol)
        db.execute("UPDATE users SET cash = (cash + (:sellPrice * :shares)) WHERE id = :id", sellPrice=sell_price[0]["sellPrice"], id=session["user_id"], shares=shares)

        # Write to history
        stock = lookup(request.form.get("symbol"))
        db.execute("INSERT INTO history (stockSymbol, name, shares, price, id) VALUES (:stockSymbol, :name, -:shares, :price, :id)", stockSymbol=stock["symbol"], name=stock["name"], shares=request.form.get("shares"), price=stock["price"], id=session["user_id"])

        # Redirect to index
        return redirect("/")

    # GET requests
    else:
        stocks = db.execute("SELECT stockSymbol FROM stocks WHERE id = :id AND shares > 0", id=session["user_id"])
        return render_template("sell.html", stocks=stocks)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)

