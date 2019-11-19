from flask import Flask, render_template
import json

app = Flask(__name__)

def getJson(jsonFileName):
    with open(jsonFileName, 'r') as data_f:
        dictFromJson = json.load(data_f)
    return dictFromJson

'''
def parseFourYearPlanJson(dictFromJson):
    # Code
''' 

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

# Schedule page
@app.route("/schedule")
def schedule():
    return render_template('schedule.html')

# Enable debugging when running
if __name__ == '__main__':
    app.run(debug=True)
