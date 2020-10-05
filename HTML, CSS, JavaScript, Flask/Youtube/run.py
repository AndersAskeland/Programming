# Imports app from app file
from website import app
 
""" Allows us to run it using > python3 app.py """
if __name__ == "__main__":
    app.run(debug=True)


""" Run via flask """
""" 1. Terminal > export FLASK_APP=app.py """
""" 2. Terminal > export FLASK_DEBUG=1 """

