from flask import Flask, render_template, request, redirect, url_for
import sys
import json
import random
import pymysql

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
                    }
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

#print(csciEmphases)
#print(csciMajorReqs)
#print(coreReqs)

def getJson(jsonFileName):
    with open(jsonFileName, 'r') as data_f:
        dictFromJson = json.load(data_f)
    return dictFromJson

'''
def parseFourYearPlanJson(dictFromJson):
    # Code
''' 

# Replace dashes with spaces in major and emphasis and then concatenate them
def concatenateMajorAndEmphasis(major, emphasis):
    major = replaceDashesWithSpaces(major)
    emphasis = replaceDashesWithSpaces(emphasis)
    return major + ", " + emphasis + " Emphasis"

# Replace dashes with spaces in an item
def replaceDashesWithSpaces(item):
    return item.replace('-',' ')

# Replace dashes with spaces in a list
def replaceDashesWithSpacesInList(itemList):
    returnList = []
    for item in itemList:
        returnList.append(replaceDashesWithSpaces(item))
    return returnList

# Initialize Student INSERT SQL statement
def sqlFromSurvey(studentID, quartersCompleted, maxQuarters, maxUnits, majorAndEmphasis, classes):
    query = ["INSERT INTO Student (StudentID, QuartersCompleted, MaxQuarters, MaxUnits, MajorEmphasis) VALUES (" + str(studentID) + ", " + str(quartersCompleted) + ", " + str(maxQuarters) + ", " + str(maxUnits) + ", \'" + majorAndEmphasis + "\');"]
    numberOfClasses = len(classes)
    for classesIndex in range(numberOfClasses):
        value = "INSERT INTO CoursesTaken (CourseID, StudentID) VALUES (\'" + classes[classesIndex] + "\', " + str(studentID) + ");"
        query.append(value)
    return query

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
    # MySQL database information
    MYSQLHOST = 'remotemysql.com'
    MYSQLPORT = 3306
    MYSQLUSER = 'GYTE3BoCBP'
    MYSQLDB = 'GYTE3BoCBP'
    MYSQLPW = '27v0MR70aB'

    # MySQL connection
    print("Connecting to MySQL server...")
    conn = pymysql.connect( MYSQLHOST,
                            user=MYSQLUSER,
                            port=MYSQLPORT,
                            passwd=MYSQLPW,
                            db=MYSQLDB)
    print("Connected to MySQL server successfully.")

    # MySQL cursor for executing queries
    cur = conn.cursor()
    print("Cursor initiated")

    # Generate random student ID
    # Currently only serves as an identifier for data entry
    # No identifier uniqueness check currently implemented
    studentID = random.randint(1000000000,1999999999)
    print("Student ID (integer):", studentID)

    # Get major and emphasis
    major = "Computer-Science"
    emphasis = request.args.get('csciEmphasis')

    # Replace numberOfQuarters and maxUnits values with HTML values
    quartersCompleted = 0
    maxQuarters = 12
    maxUnits = 19

    # Preference on major/core classes only
    classesPreferred = request.args.get('classPreferences')

    # Return to survey page if no emphasis declared
    # No error message is displayed currently
    if emphasis == None:
        return render_template('survey.html', csciEmphases=csciEmphases, csciMajorReqs=csciMajorReqs, coreReqs=coreReqs)
    else:
        majorAndEmphasis = concatenateMajorAndEmphasis(major, emphasis)

    print("Major:", majorAndEmphasis)
    print("Core/major preference:", classesPreferred)

    # Initialize lists, replace dashes in names of classes with spaces
    majorClassesTaken = replaceDashesWithSpacesInList(request.args.getlist('csciMajorReqsTaken'))
    coresTaken = replaceDashesWithSpacesInList(request.args.getlist('coreReqsTaken'))
    allClassesTaken = majorClassesTaken + coresTaken
    print("\nAll classes taken:")
    for aClass in allClassesTaken:
        print(aClass)

    # Execute insert commands to MySQL
    sqlCommands = sqlFromSurvey(studentID, quartersCompleted, maxQuarters, maxUnits, majorAndEmphasis, allClassesTaken)
    print("\nSQL commands:")
    for sqlCommand in sqlCommands:
        print(sqlCommand)
        cur.execute(sqlCommand)

    # Commit commands to database
    conn.commit()
    print("\nSQL commands committed to database")

    # Open 4-year-plan json from algorithm
    # Using sample plan json for now
    fourYearPlan = getJson('FourYearPlan.json')

    # Close connection to database
    cur.close()
    print("Cursor closed.")
    conn.close()
    print("Connection to database closed.")

    return render_template('schedule.html', fourYearPlan=fourYearPlan)

# Enable debugging when running
if __name__ == '__main__':
    app.run(debug=True)
