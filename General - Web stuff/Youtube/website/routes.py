from flask import render_template, url_for, flash, redirect
from website.forms import RegistrationForm, LoginForm # Classes made in forms.py
from website import app, db, bcrypt
# Models need to be here, as models use db
from website.models import User, Post
from flask_login import login_user, current_user, logout_user, login_required, login_required


""" We create the database using pythonterminal """
# From app import db
# db.create_all()
# Delete data > db.drop_all()

""" Create list of dicts """
posts = [
    {
        "author": "Anders Askeland",
        "title": "Post 1",
        "content": "Stuff  am writing about",
        "date_posted": "April 20, 2020"
    },
    {
        "author": "Louise Rold",
        "title": "Post 2",
        "content": "Stuff louise is writing about. Maybe a review?",
        "date_posted": "April 22, 2020" 
    }
]


# Home
@app.route("/")
@app.route("/home") # You can route set several sites
def home():
    return render_template("home.html", posts=posts)


# About
@app.route("/about")
def about():
    return render_template("about.html", title="About")


# Register
@app.route("/register", methods=["GET", "POST"])
def register():
    # Check user login
    if current_user.is_authenticated:
        return redirect(url_for('home'))
        
    # Set registration class to form
    form = RegistrationForm()

    if form.validate_on_submit():
        # Create password hash
        hashed_password = bcrypt.generate_password_hash(form.password.data).decode('utf-8')
        
        # Add user to SQL
        user = User(username=form.username.data, email=form.email.data, password=hashed_password)
        db.session.add(user)
        db.session.commit()

        # Flash
        flash('Your account has been created! You are now able to log in', 'success')
        return redirect(url_for('login'))
    return render_template("register.html", title="Register", form=form)

# Login
@app.route("/login", methods=["GET", "POST"])
def login():
    if current_user.is_authenticated:
        return redirect(url_for('home'))
    # Set login class to form
    form = LoginForm()
    if form.validate_on_submit():
        user = User.query.filter_by(email=form.email.data).first()

        if user and bcrypt.check_password_hash(user.password, form.password.data):
            login_user(user, remember=form.remember.data)
            return redirect(url_for("home"))
        else:
            flash("Login Unsuccessful. Please check email and password", "danger")

    return render_template("login.html", title="Login", form=form)

# Logout
@app.route("/logout")
def logout():
    logout_user()
    return redirect(url_for("home"))


# Account menu
@app.route("/account")
@login_required
def account():
    return render_template("account.html", title="account")
