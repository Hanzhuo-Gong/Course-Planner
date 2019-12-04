from flask import Flask, render_template, request, redirect, url_for
import sys
import json
import random
import pymysql
import subprocess

app = Flask(__name__)

# Paths to algorithm files
algo = 'FourYearPlanAlgorithm'
algoClass = algo + '/scuClass.cpp'
algoHashMap = algo + '/HashMap.cpp'
algoPlan = algo + '/FourYearPlan.cpp'
algoStudent = algo + '/Student.cpp'
algoDriver = algo + '/driver.cpp'

# Path to four-year JSON file
fourYearPlanJson = 'FourYearPlan.json'

# SQLAPI++ files
sqlApiInclude = algo + '/SQLAPI/include'
sqlApiLib = algo + '/SQLAPI/lib'

# Paths to JSON files containing survey questions and options
surveysPath = 'setup/surveyQuestionJsons'
csciEmphasesJson = surveysPath + '/csciEmphases.json'
# prefersMajorClassesOnlyJson = surveysPath + '/prefersMajorClassesOnly.json'
csciMajorReqsJson = surveysPath + '/csciMajorReqs.json'
coreReqsJson = surveysPath + '/coreReqs.json'

def getJson(jsonFileName):
    with open(jsonFileName, 'r') as data_f:
        dictFromJson = json.load(data_f)
    return dictFromJson

# Replace dashes with spaces in major and emphasis and then concatenate them
def concatenateMajorAndEmphasis(major, emphasis):
    try:
        major = replaceDashesWithSpaces(major)
        emphasis = replaceDashesWithSpaces(emphasis)
        return major + ", " + emphasis + " Emphasis"
    except:
        raise TypeError("Major and emphasis could not be concatenated")

# Replace dashes with spaces in an item
def replaceDashesWithSpaces(item):
    try:
        return item.replace('-',' ')
    except:
        print("Dashes of item could not be replaced")
        return item

# Replace dashes with spaces in a list
def replaceDashesWithSpacesInList(itemList):
    try:
        returnList = []
        for item in itemList:
            returnList.append(replaceDashesWithSpaces(item))
        return returnList
    except:
        print("Could not replace dashes with spaces in list")
        return itemList

# Initialize Student INSERT SQL statement
def sqlFromSurvey(studentID, quartersCompleted, maxQuarters, maxUnits, majorAndEmphasis, classes):
    try:
        query = ["INSERT INTO Student (StudentID, QuartersCompleted, MaxQuarters, MaxUnits, MajorEmphasis) VALUES (" + str(studentID) + ", " + str(quartersCompleted) + ", " + str(maxQuarters) + ", " + str(maxUnits) + ", \'" + majorAndEmphasis + "\');"]
        numberOfClasses = len(classes)
        for classesIndex in range(numberOfClasses):
            value = "INSERT INTO CoursesTaken (CourseID, StudentID) VALUES (\'" + classes[classesIndex] + "\', " + str(studentID) + ");"
            query.append(value)
        return query
    except:
        raise Exception("Could not generate SQL INSERT INTO statements")

def getMysqlConn():
    try:
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
        return [conn, cur]
    except:
        raise Exception("Could not connect to MySQL server.")

# Home page
@app.route("/")
@app.route("/index")
@app.route("/home")
def index():
    return render_template('index.html')

# Survey page
@app.route("/survey")
def survey():
    csciEmphases = getJson(csciEmphasesJson)
    csciMajorReqs = getJson(csciMajorReqsJson)
    coreReqs = getJson(coreReqsJson)

#   Print to console log for debugging
#   print(csciEmphases)
#   print(csciMajorReqs)
#   print(coreReqs)

    return render_template('survey.html', csciEmphases=csciEmphases, csciMajorReqs=csciMajorReqs, coreReqs=coreReqs)

# Schedule page
@app.route("/schedule")
def schedule():
    # Connect to MySQL
    db = getMysqlConn()
    conn = db[0]
    cur = db[1]

    # Generate random student ID
    # Currently only serves as an identifier for data entry
    # No identifier uniqueness check currently implemented
    studentID = random.randint(-1999999999,-1000000000)
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

    # Compile C++ 4-year plan algorithm as subprocess
    subprocess.check_call(
        ('g++', '-I', sqlApiInclude, '-L', sqlApiLib, '-lsqlapi', '-o', 'classScheduler.out', algoClass, algoHashMap, algoPlan, algoStudent, algoDriver),
        stdin=subprocess.DEVNULL)

    with open(fourYearPlanJson, 'w') as outfile:
        subprocess.check_call(
            ('./classScheduler.out',),
#           stdin = infile,
            stdout = outfile,
            universal_newlines = True)

    # Using sample plan json for now
    fourYearPlan = getJson(fourYearPlanJson)

    # Close connection to database
    cur.close()
    print("Cursor closed.")
    conn.close()
    print("Connection to database closed.")

    return render_template('schedule.html', fourYearPlan=fourYearPlan)

# Enable debugging when running
if __name__ == '__main__':
    app.run(debug=True)
