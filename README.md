# Course-Planner

Website: https://xiaogong1.github.io/Course-Planner/

A group project for Santa Clara Univerisity CSCI 187. Course Planner help students with their education plan.
Course Planner generate recommend classes base on students needed. Our group still developing the project. We will
update the project periodically.

SETUP:
Install flask for python3 using 'pip3 install flask'
Contact jpark3@scu.edu if you are having difficulties running the app

RUNNING:
1. Run web app using 'python3 main.py'
2. Navigate to 'localhost:5000' to access the frontend


11/1/19 -Completed the main page

KNOWN BUGS:
- As of 11/18/19, the current schema for the database does not take into account classes that require one prerequisite OR another

SQLAPI++ REQUIRED FOR C++ ALGORITHM:
- Compile algorithm using "g++ -I FourYearPlanAlgorithm/SQLAPI/include -L FourYearPlanAlgorithm/SQLAPI/lib -lsqlapi -o classScheduler.out FourYearPlanAlgorithm/scuClass.cpp FourYearPlanAlgorithm/HashMap.cpp FourYearPlanAlgorithm/FourYearPlan.cpp FourYearPlanAlgorithm/Student.cpp FourYearPlanAlgorithm/driver.cpp" (it's a handful!)
- Please copy the libsqlapi.dylib file from FourYearPlanAlgorithm/SQLAPI/lib to /usr/local/lib
