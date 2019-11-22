#include "Classes.h"

using namespace Schedule;

void printHeader(string testName) {
  cout<<endl;
  cout<<"------------------------------------"<<endl;
  cout<<testName<<" tests:"<<endl;
  cout<<"------------------------------------"<<endl;
  cout<<endl;
}

int main() {

  printHeader("Class.h");

  Class CS10 ("CS10", "Intro to Computer Science", "Computer Science", 0, 5, 0, 0, "FWS");
  CS10.printDetails();

  Class CS60 ("CS60", "Object-Oriented Programming", "Computer Science", 0, 5, 0, 0, "WS");
  CS60.pushPreReq("CS10", false);
  CS60.setPreReq("CS10", true);
  CS60.printDetails();
  CS60.feasible();

  Class CS61 ("CS61", "Data Structures", "Computer Science", 0, 5, 0, 0, "FS");
  CS61.pushPreReq("CS60", false);
  CS61.printDetails();

  Class MATH11 ("MATH11", "Calculus and Analytic Geometry I", "Math", 0, 5, 0, 0, "FWS");
  MATH11.printDetails();

  Class MATH12 ("MATH12", "Calculus and Analytic Geometry II", "Math", 0, 5, 0, 0, "FWS");
  MATH12.pushPreReq("MATH11", false);
  MATH12.printDetails();

  Class MATH13 ("MATH13", "Calculus and Analytic Geometry III", "Math", 0, 5, 0, 0, "FWS");
  MATH13.pushPreReq("MATH12", false);
  MATH13.printDetails();

  Class MATH14 ("MATH14", "Calculus and Analytic Geometry IV", "Math", 0, 5, 0, 0, "FWS");
  MATH14.pushPreReq("MATH13", false);
  MATH14.printDetails();
  MATH14.feasible();

  Class CS163A ("CS163A", "Theory of Algorithms", "Computer Science", 0, 5, 0, 0, "FWS");
  CS163A.pushPreReq("MATH51", false);
  CS163A.pushPreReq("CS61", false);
  CS163A.printDetails();
  CS163A.feasible();

  Class CS165 ("CS165", "Linear Programming", "Computer Science", 0, 5, 0, 0, "WO");
  CS165.printDetails();
  CS165.available("Winter", 2020);
  CS165.available("Fall", 2021);
  CS165.available("Winter", 2021);

  printHeader("Classes.h");

  Classes test;
  test.insert(CS10);
  test.insert(CS60);
  test.insert(CS61);
  test.insert(MATH11);
  test.insert(MATH12);
  test.insert(MATH13);
  test.insert(MATH14);
  test.insert(CS163A);
  test.insert(CS165);
  test.printDetails("CS165");
  test.getClassState("CS165");
  test.getClassFeasible("CS165");
  test.getClassAvailable("CS165", "Winter",2020);
  test.getClassAvailable("CS165", "Fall", 2021);
  test.getClassAvailable("CS165", "Winter", 2021);

  test.printPreReqs("CS163A");
  test.printClassIDs();


}
