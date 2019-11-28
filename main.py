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

# Path to input file for algorithm
classObjectsFile = 'AlgorithmInput.txt'

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
        MYSQLHOST = 'localhost'
        MYSQLUSER = 'root'
        MYSQLDB = 'PlanToGrad'
        MYSQLPW = None

#       MYSQLHOST = 'remotemysql.com'
#       MYSQLPORT = 3306
#       MYSQLUSER = 'GYTE3BoCBP'
#       MYSQLDB = 'GYTE3BoCBP'
#       MYSQLPW = '27v0MR70aB'

        # MySQL connection
        print("Connecting to MySQL server...")
        conn = pymysql.connect( MYSQLHOST,
                                user=MYSQLUSER,
#                               port=MYSQLPORT,
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

#   # Execute insert commands to MySQL
#   sqlCommands = sqlFromSurvey(studentID, quartersCompleted, maxQuarters, maxUnits, majorAndEmphasis, allClassesTaken)
#   print("\nSQL commands:")
#   for sqlCommand in sqlCommands:
#       print(sqlCommand)
#       cur.execute(sqlCommand)

#   # Commit commands to database
#   conn.commit()
#   print("\nSQL commands committed to database")

    # Write to algorithm input file
    with open(classObjectsFile, 'w') as infile:
        # Query major classes and write to file
        queryMajorClasses = "SELECT a.CourseID, CourseName, QuarterOffered, CreditGiven FROM Classes AS a LEFT JOIN MajorReqs AS b ON a.CourseID = b.CourseID WHERE MajorName = \'" + majorAndEmphasis + "\';"
        cur.execute(queryMajorClasses)
        queriedMajorClasses = cur.fetchall()
        for aClass in queriedMajorClasses:
            classID = aClass[0]
            className = aClass[1]
            subject = majorAndEmphasis
            quarterOffered = aClass[2]
            creditGiven = aClass[3]
            lineToAppend = classID + ";" + className + ";" + subject + ";" + quarterOffered + ";" + str(creditGiven) + ";"
            queryPrereqs = "SELECT PreReqName from Prereqs where CourseID=\'" + classID + "\'"
            cur.execute(queryPrereqs)
            queriedPrereqs = cur.fetchall()
            for prereq in queriedPrereqs:
                lineToAppend = lineToAppend + prereq[0] + ";"
            infile.write(lineToAppend + "\n")
        infile.write("!\n")
        # Query core classes and write to file
        queryCoreClasses = "SELECT a.CourseID, CourseName, QuarterOffered, CreditGiven FROM Classes AS a LEFT JOIN MajorReqs AS b ON a.CourseID = b.CourseID WHERE MajorName = \'Core\';"
        cur.execute(queryCoreClasses)
        queriedCoreClasses = cur.fetchall()
        for aClass in queriedCoreClasses:
            classID = aClass[0]
            className = aClass[1]
            subject = majorAndEmphasis
            quarterOffered = aClass[2]
            creditGiven = aClass[3]
            lineToAppend = classID + ";" + className + ";" + subject + ";" + quarterOffered + ";" + str(creditGiven) + ";"
            queryPrereqs = "SELECT PreReqName from Prereqs where CourseID=\'" + classID + "\'"
            cur.execute(queryPrereqs)
            queriedPrereqs = cur.fetchall()
            for prereq in queriedPrereqs:
                lineToAppend = lineToAppend + prereq[0] + ";"
            infile.write(lineToAppend + "\n")
        infile.write("!\n")
        # Write two random emphasis classes lol
        infile.write("CSCI 168;Computer Graphics;" + majorAndEmphasis + ";F;5;CSCI 10;MATH 13;\nCOEN 166;Artificial Intelligence;" + majorAndEmphasis + ";FS;5;CSCI 61;MATH 51;\n")
        infile.write("!\n")
        # Classes previously taken
        for classID in allClassesTaken:
            lineToWrite = ""
            queryTakenClass = "SELECT CourseName, QuarterOffered, CreditGiven from Classes where CourseID=\'" + classID + "\'"
            cur.execute(queryTakenClass)
            queriedTakenClass = cur.fetchall()
            print(queriedTakenClass)
            className = queriedTakenClass[0][0]
            subject = majorAndEmphasis
            quarterOffered = queriedTakenClass[0][1]
            creditGiven = queriedTakenClass[0][2]
            lineToAppend = classID + ";" + className + ";" + subject + ";" + quarterOffered + ";" + str(creditGiven) + ";"
            infile.write(lineToAppend + "\n")

    # Compile C++ 4-year plan algorithm as subprocess
    subprocess.check_call(
        ('g++', '-o', 'classScheduler.out', algoClass, algoHashMap, algoPlan, algoStudent, algoDriver),
        stdin=subprocess.DEVNULL)

    # Run executable
    with open(fourYearPlanJson, 'w') as outfile:
        subprocess.check_call(
            ('./classScheduler.out', classObjectsFile),
#           stdin = None,
            stdout = outfile,
            universal_newlines = True)

    # Delete all the bullshit outputted by the executable before the JSON
    lines = open(fourYearPlanJson, 'r').readlines()
    search = "["
    for jsonStart, line in enumerate(lines):
        if search in line:
            break
    if jsonStart < len(lines) - 1:
        with open(fourYearPlanJson, 'w') as outfile:
            outfile.write(''.join(lines[jsonStart:]))

    # Store four year plan to Python dict from JSON
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
