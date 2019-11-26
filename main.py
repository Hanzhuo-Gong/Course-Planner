from flask import Flask, render_template, request, redirect, url_for
import json
import uuid
import cx_Oracle

app = Flask(__name__)

# Connection not working (DPI-1047)
'''
# Connect to Database
dsn_tns = cx_Oracle.makedsn('dagobah.engr.scu.edu', '1521', service_name='db    11g')
conn = cx_Oracle.connect(user='jpark3', password='forcsci187', dsn=dsn_tns
)
cur = conn.cursor()
'''

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

'''
prefersMajorClassesOnly = {
    'question'  : 'Do you prefer to take only major/core classes only or all other classes?',
    'options'   : [
                    {
                      'name':'Major/Core classes only', 
                      'id':'Major-Core-Classes-Only'
                    },
                    {
                      'name':'Open to all classes',
                      'id':'All-classes'
                    },
                  ]
}
'''

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
                      },
                      {
                        'name':'MATH 51',
                        'id':'MATH-51'
                      },
                      {
                        'name':'MATH 53',
                        'id':'MATH-53'
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
                        'name':'MATH 122',
                        'id':'MATH-122'
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
                        'name':'COEN 177 and L',
                        'id':'COEN-177-and-L'
                      },
                      {
                        'name':'CSCI 162 (Algorithms and Complexity)',
                        'id':'CSCI-162'
                      },
                      {
                        'name':'CSCI 163B (Algorithms and Complexity)',
                        'id':'CSCI-163B'
                      },
                      {
                        'name':'MATH 177 (Algorithms and Complexity)',
                        'id':'MATH-177'
                      }
                    ],
                    [
                      {
                        'name':'CSCI 183 (Data Science)',
                        'id':'CSCI-183'
                      },
                      {
                        'name':'CSCI 184 (Data Science)',
                        'id':'CSCI-184'
                      },
                      {
                        'name':'MATH 123 (Data Science)',
                        'id':'MATH-123'
                      },
                      {
                        'name':'CSCI 169 (Software)',
                        'id':'CSCI-169'
                      },
                      {
                        'name':'CSCI 187 (Software)',
                        'id':'CSCI-187'
                      },
                      {
                        'name':'COEN 146 and L (Software)',
                        'id':'COEN-146-and-L'
                      },
                      {
                        'name':'CSCI 180 (Security)',
                        'id':'CSCI-180'
                      },
                      {
                        'name':'MATH 178 (Security)',
                        'id':'MATH-178'
                      },
                      {
                        'name':'CSCI 181 (Security)',
                        'id':'CSCI-181'
                      }
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
                      },
                      {
                        'name':'Experiential Learning and Social Justice',
                        'id':'ELSJ'
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
    studentID = uuid.uuid4()
    emphasis = request.args.get('csciEmphasis')
    # Replace numberOfQuarters and maxUnits values with HTML values
    numberOfQuarters = 12
    maxUnits = 19
    classesPreferred = request.args.get('classPreferences')
    majorClassesTaken = request.args.getlist('csciMajorReqsTaken')
    coresTaken = request.args.getlist('coreReqsTaken')

    print(studentID.int)
    print(emphasis)
    print(classesPreferred)
    print(majorClassesTaken)
    print(coresTaken)

    return render_template('schedule.html')

# Enable debugging when running
if __name__ == '__main__':
    app.run(debug=True)
