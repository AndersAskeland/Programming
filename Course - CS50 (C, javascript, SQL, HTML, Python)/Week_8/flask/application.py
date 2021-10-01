import random
from flask import Flask, render_template, request


app = Flask(__name__) # __name__ means I will server the app from this py script

@app.route("/")
def index():
    number = random.randint(1,20)
    return render_template("index.html", number = number)

@app.route("/goodbye")
def goodbye():
    return("Goodbye")

@app.route("/submit")
def submit():
    name = request.args.get("name")
    if not name:
        return render_template("failure.html")
    return render_template("hello.html", name=name)