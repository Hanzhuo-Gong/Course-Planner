from flask import Flask, render_template

app = Flask(__name__)

# Home page
@app.route("/")
@app.route("/index")
@app.route("/home")
def index():
    return render_template('index.html')

# Survey page
@app.route("/survey")
def survey():
    return render_template('survey.html')

# Enable debugging when running
if __name__ == '__main__':
    app.run(debug=True)
