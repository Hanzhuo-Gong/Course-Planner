from flask import Flask, render_template, request, redirect, url_for
import sys
import json
import uuid
import pymysql

app = Flask(__name__)

# MySQL database information
MYSQLHOST = 'dbserver.engr.scu.edu'
MYSQLPORT = 3306
MYSQLUSER = 'jpark3'
MYSQLDB = 'sdb_jpark3'

'''
# Set first command line argument as MySQL database password
if len(sys.argv) == 2:
    MYSQLPW = str(sys.argv[1])
# Otherwise exit program
else:
    print("Usage: Enter password for MySQL server as 1st command line argument")
    sys.exit(1)

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
def initInsertToStudent(studentID, quartersCompleted, maxQuarters, maxUnits, majorAndEmphasis):
    query = ["INSERT INTO Student (StudentID, QuartersCompleted, MaxQuarters, MaxUnits, MajorEmphasis)"]
    insertValues = "VALUES (" + str(studentID) + ", " + str(quartersCompleted) + ", " + str(maxQuarters) + ", " + str(maxUnits) + ", " + majorAndEmphasis + ");"
    query.append(insertValues)
    return query

# Initialize CoursesTaken INSERT SQL statement
def initInsertToCoursesTaken(studentID, classes):
    query = ["INSERT INTO CoursesTaken (CourseID, StudentID)","VALUES"]
    numberOfClasses = len(classes)
    for classesIndex in range(numberOfClasses):
        value = "(" + classes[classesIndex] + ", " + str(studentID) + ")"
        if classesIndex < numberOfClasses - 1:
            endOfValue = ","
        else:
            endOfValue = ";"
        value = value + endOfValue
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
    # Generate student ID
    studentID = uuid.uuid4()

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
    if emphasis == None:
        return render_template('survey.html', csciEmphases=csciEmphases, csciMajorReqs=csciMajorReqs, coreReqs=coreReqs)
    else:
        majorAndEmphasis = concatenateMajorAndEmphasis(major, emphasis)

    # Initialize lists, replace dashes in names of classes with spaces
    majorClassesTaken = replaceDashesWithSpacesInList(request.args.getlist('csciMajorReqsTaken'))
    coresTaken = replaceDashesWithSpacesInList(request.args.getlist('coreReqsTaken'))
    allClassesTaken = majorClassesTaken + coresTaken

    # Execute insert commands to MySQL
    sqlCommands = initInsertToStudent(studentID.int, quartersCompleted, maxQuarters, maxUnits, majorAndEmphasis) + initInsertToCoursesTaken(studentID.int, allClassesTaken)
#   for line in sqlCommands:
#       cur.execute(line)

#   # Commit commands to database
#   conn.commit()

    # Open 4-year-plan json from algorithm
    # Using sample plan json for now
    fourYearPlan = getJson('FourYearPlan.json')

    # Debugging on console log
    print("Student ID (integer):", studentID.int)
    print("Major:", majorAndEmphasis)
    print("Core/major preference:", classesPreferred)
    print("Major classes taken:", majorClassesTaken)
    print("Core classes taken:", coresTaken)
    print("All classes taken:", allClassesTaken)
    print("SQL commands:", sqlCommands)

    return render_template('schedule.html', fourYearPlan=fourYearPlan)

# Enable debugging when running
if __name__ == '__main__':
    app.run(debug=True)
