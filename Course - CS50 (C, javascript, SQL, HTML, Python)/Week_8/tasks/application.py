# Packages
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# Settings
app = Flask(__name__) 
app.config["SERSSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app) # Enable sessions


@app.route("/")
def tasks():
    # Check if they have cookie. If not give them one.
    if "todos" not in session:
        session["todos"] = []
    return render_template('tasks.html', todos=session["todos"])

@app.route("/add", methods=["GET", "POST"])
def add():
    # Send request
    if request.method == "GET":
        return render_template("add.html")
    # 
    elif request.method == "POST":
        todo = request.form.get("task")
        session["todos"].append(todo)
        return redirect("/")


