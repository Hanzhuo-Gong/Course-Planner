from flask import Flask, render_template, request, redirect, url_for
import json

app = Flask(__name__)

csciEmphases = {
    'question'  : 'Choose your emphasis',
    'options'   : [
                    {
                      'name':'Algorithms and Complexity', 
                      'id':'Algorithms-and-Complexity'
                    },
                    {
                      'name':'Data Science',
                      'id':'Data-Science'
                    },
                    {
                      'name':'Software',
                      'id':'Software'
                    },
                    {
                      'name':'Security',
                      'id':'Security'
                    }
                  ]
}

csciMajorReqs = {
    'question'  : 'Department Requirements',
    'options'   : [
                    [
                      {
                        'name':'CSCI 10 and L',
                        'id':'CSCI-10-and-L'
                      },
                      {
                        'name':'CSCI 60 and L',
                        'id':'CSCI-60-and-L'
                      },
                      {
                        'name':'CSCI 61',
                        'id':'CSCI-61'
                      },
                      {
                        'name':'MATH 11',
                        'id':'MATH-11'
                      },
                      {
                        'name':'MATH 12',
                        'id':'MATH-12'
                      },
                      {
                        'name':'MATH 13',
                        'id':'MATH-13'
                      },
                      {
                        'name':'MATH 14',
                        'id':'MATH-14'
                      }
                    ],
                    [
                      {
                        'name':'COEN 20 and L',
                        'id':'COEN-20-and-L'
                      },
                      {
                        'name':'COEN 21 and L',
                        'id':'COEN-21-and-L'
                      },
                      {
                        'name':'MATH 51',
                        'id':'MATH-51'
                      },
                      {
                        'name':'MATH 53',
                        'id':'MATH-53'
                      },
                      {
                        'name':'CSCI 161',
                        'id':'CSCI-161'
                      },
                      {
                        'name':'CSCI 163A',
                        'id':'CSCI-163A'
                      },
                      {
                        'name':'MATH 122',
                        'id':'MATH-122'
                      }
                    ],
                    [
                      {
                        'name':'COEN 177 and L',
                        'id':'COEN-177-and-L'
                      },
                      {
                        'name':'CSCI Emphasis 1',
                        'id':'CSCI-Emphasis-1'
                      },
                      {
                        'name':'CSCI Emphasis 2',
                        'id':'CSCI-Emphasis-2'
                      },
                      {
                        'name':'CSCI Emphasis 3',
                        'id':'CSCI-Emphasis-3'
                      },
                      {
                        'name':'CSCI Emphasis 4',
                        'id':'CSCI-Emphasis-4'
                      },
                      {
                        'name':'CSCI Emphasis 5',
                        'id':'CSCI-Emphasis-5'
                      },
                    ]
                  ]
}

coreReqs = {
    'question'  : 'College and University Requirements',
    'options'   : [
                    [
                      {
                        'name':'CTW 1',
                        'id':'CTW-1'
                      },
                      {
                        'name':'CTW 2',
                        'id':'CTW-2'
                      },
                      {
                        'name':'Advanced Writing',
                        'id':'Advanced-Writing'
                      },
                      {
                        'name':'Ethics',
                        'id':'Ethics'
                      },
                      {
                        'name':'Diversity',
                        'id':'Diversity'
                      },
                      {
                        'name':'Arts',
                        'id':'Arts'
                      }
                    ],
                    [
                      {
                        'name':'Language 1',
                        'id':'Language-1'
                      },
                      {
                        'name':'Language 2',
                        'id':'Language-2'
                      },
                      {
                        'name':'Natural Science',
                        'id':'Natural-Science'
                      },
                      {
                        'name':'RTC 1',
                        'id':'RTC-1'
                      },
                      {
                        'name':'RTC 2',
                        'id':'RTC-2'
                      },
                      {
                        'name':'RTC 3',
                        'id':'RTC-3'
                      }
                    ],
                    [
                      {
                        'name':'Social Science',
                        'id':'Social-Science'
                      },
                      {
                        'name':'Culture and Ideas 1',
                        'id':'Culture-and-Ideas-1'
                      },
                      {
                        'name':'Culture and Ideas 2',
                        'id':'Culture-and-Ideas-2'
                      },
                      {
                        'name':'Culture and Ideas 3',
                        'id':'Culture-and-Ideas-3'
                      },
                      {
                        'name':'Civic Engagement',
                        'id':'Civic-Engagement'
                      }
                    ]
                  ]
}

print(csciEmphases)
print(csciMajorReqs)
print(coreReqs)

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
    return render_template('survey.html', csciEmphases=csciEmphases, csciMajorReqs=csciMajorReqs, coreReqs=coreReqs)

# Schedule page
@app.route("/schedule")
def schedule():
    emphasis = request.args.get('csciEmphasis')
    majorClassesTaken = request.args.getlist('csciMajorReqsTaken')
    coresTaken = request.args.getlist('coreReqsTaken')

    print(emphasis)
    print(majorClassesTaken)
    print(coresTaken)

    return render_template('schedule.html')

# Enable debugging when running
if __name__ == '__main__':
    app.run(debug=True)
