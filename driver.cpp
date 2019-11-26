#include "Major.h"
#include "Emphasis.h"
#include "Core.h"

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

  Class CS10 ("CS10", "Intro to Computer Science", "Computer Science", 0, 5, 0, false, "FWS");
  CS10.printDetails();

  Class CS60 ("CS60", "Object-Oriented Programming", "Computer Science", 0, 5, 0, false, "WS");
  CS60.pushPreReq("CS10", false);
  CS60.setPreReq("CS10", true);
  CS60.printDetails();
  CS60.feasible(0);

  Class CS61 ("CS61", "Data Structures", "Computer Science", 0, 5, 0, false, "FS");
  CS61.pushPreReq("CS60", false);
  CS61.printDetails();

  Class MATH11 ("MATH11", "Calculus and Analytic Geometry I", "Math", 0, 5, 0, false, "FWS");
  MATH11.printDetails();

  Class MATH12 ("MATH12", "Calculus and Analytic Geometry II", "Math", 0, 5, 0, false, "FWS");
  MATH12.pushPreReq("MATH11", false);
  MATH12.printDetails();

  Class MATH13 ("MATH13", "Calculus and Analytic Geometry III", "Math", 0, 5, 0, false, "FWS");
  MATH13.pushPreReq("MATH12", false);
  MATH13.printDetails();

  Class MATH14 ("MATH14", "Calculus and Analytic Geometry IV", "Math", 0, 5, 0, false, "FWS");
  MATH14.pushPreReq("MATH13", false);
  MATH14.printDetails();
  MATH14.feasible(0);

  // Class NATSCI ("NATSCI", "Natural Science", "Natural Science", 0, 5, 0, false, "FWS");

  Class COEN20 ("COEN20", "Intro to Embedded Systems", "Computer Engineering", 0, 5, 0, false, "FWS");
  COEN20.pushPreReq("CS60", false);

  Class COEN21 ("COEN21", "Intro to Logic Design", "Computer Engineering", 0, 5, 0, false, "FWS");

  Class MATH51 ("MATH51", "Discrete Mathematics", "Math", 0, 4, 0, false, "FWS");

  Class MATH53 ("MATH53", "Linear Algebra", "Math", 0, 4, 0, false, "FWS");
  MATH53.pushPreReq("MATH13", false);

  Class CS161 ("CS161", "Theory of Automata and Languages 1", "Computer Science", 0, 5, 0, false, "FW");
  CS161.pushPreReq("MATH51", false);

  Class CS163A ("CS163A", "Theory of Algorithms", "Computer Science", 0, 5, 0, false, "FWS");
  CS163A.pushPreReq("MATH51", false);
  CS163A.pushPreReq("CS61", false);
  CS163A.printDetails();
  CS163A.feasible(0);

  Class MATH122 ("MATH122", "Probability and Statistics 1", "Math", 0, 5, 0, false, "FW");
  MATH122.pushPreReq("MATH14", false);

  printHeader("Classes.h");

  Classes major;
  major.insert(CS10);
  major.insert(CS60);
  major.insert(CS61);
  major.insert(MATH11);
  major.insert(MATH12);
  major.insert(MATH13);
  major.insert(MATH14);
  major.insert(COEN20);
  major.insert(COEN21);
  major.insert(MATH51);
  major.insert(MATH53);
  major.insert(CS161);
  major.insert(CS163A);
  major.insert(MATH122);

  major.printDetails("CS161");
  major.getClassState("CS161");
  major.getClassFeasible("CS161", 0);
  major.getClassAvailable("CS161", "Winter",2020);
  major.getClassAvailable("CS161", "Fall", 2021);
  major.getClassAvailable("CS161", "Winter", 2021);

  major.printPreReqs("CS163A");
  major.printClassIDs();

  printHeader("Major.h");

  Major majorTest("Computer Science", major);
  majorTest.printMajorDetails();
  majorTest.printClassDetails("CS10");
  majorTest.complete();
  majorTest.markClassFinished("CS10");
  majorTest.complete();

  printHeader("Emphasis.h");

  Class CS169 ("CS169", "Programming Languages", "Computer Science", 0, 5, 0, false, "S");
  CS169.pushPreReq("CS61", false);
  CS169.pushPreReq("MATH51", false);
  Class CS187 ("CS187", "Design Management of Software", "Computer Science", 0, 5, 0, false, "F");
  CS187.pushPreReq("CS61", false);
  Class COEN146 ("COEN146", "Computer Networks", "Computer Engineering", 0, 5, 0, false, "FWS");
  COEN146.pushPreReq("CS61", false);

  Classes eRequired;
  eRequired.insert(CS169);
  eRequired.insert(CS187);
  eRequired.insert(COEN146);

  Class CS183 ("CS183", "Data Science", "Computer Science", 0, 5, 0, false, "WS");
  CS183.pushPreReq("CS61", false);
  CS183.pushPreReq("MATH53", false);
  CS183.pushPreReq("MATH122", false);

  Class CS163B ("CS163B", "Advanced Algorithms", "Computer Science", 0, 5, 0, false, "W");
  CS163B.pushPreReq("CS163A", false);

  Class CS168 ("CS168", "Computer Graphics", "Computer Science", 0, 5, 0, false, "F");
  CS168.pushPreReq("CS10", false);
  CS168.pushPreReq("MATH13", false);

  Class COEN163 ("COEN163", "Web Usability", "Computer Engineering", 0, 5, 0, false, "FWS");
  COEN163.pushPreReq("CS61", false);

  Class COEN166 ("COEN166", "Artificial Intelligience", "Computer Engineering", 0, 5, 0, false, "FS");
  COEN166.pushPreReq("CS61", false);
  COEN166.pushPreReq("MATH51", false);

  Classes eTwoMore;
  eTwoMore.insert(CS183);
  eTwoMore.insert(CS163B);
  eTwoMore.insert(CS168);
  eTwoMore.insert(COEN163);
  eTwoMore.insert(COEN166);

  Emphasis emphasisTest("Software", eRequired, eTwoMore);
  emphasisTest.printEmphasisDetails();
  emphasisTest.requiredComplete();
  emphasisTest.twoMoreComplete();
  emphasisTest.markClassFinished("CS168");
  emphasisTest.markClassFinished("CS187");
  emphasisTest.requiredComplete();
  emphasisTest.twoMoreComplete();
  emphasisTest.printClassDetails("COEN146");
  emphasisTest.printClassDetails("COEN168");

  printHeader("Core.h");

  Class CTW1 ("CTW1", "Critical Thinking and Writing 1", "English", 0, 4, 0, false, "FW");

  Class CTW2 ("CTW2", "Critical Thinking and Writing 2", "English", 0, 4, 0, false, "WS");
  CTW2.pushPreReq("CTW1", false);

  Class AW("AW", "Advanced Writing", "English", 0, 5, 0, false, "FWS");
  AW.pushPreReq("CTW2", false);

  Class ETH("ETH", "Ethics", "Ethics", 0, 4, 0, false, "FWS");

  Class DIV("DIV", "Diversity", "Diversity", 0, 5, 0, false, "FWS");

  Class ARTS("ARTS", "Arts", "Arts", 0, 4, 0, false, "FWS");

  Class LANG1("LANG1", "Foreign Language 1", "Foreign Language", 0, 4, 0, false, "FWS");

  Class LANG2("LANG2", "Foreign Language 2", "Foreign Language", 0, 4, 0, false, "FWS");

  Class NATSCI ("NATSCI", "Natural Science", "Natural Science", 0, 5, 0, false, "FWS");

  Class RTC1("RTC1", "Religion Theology and Culture 1", "Religion", 0, 4, 0, false, "FWS");

  Class RTC2("RTC2", "Religion Theology and Culture 2", "Religion", 0, 4, 0, false, "FWS");

  Class RTC3("RTC3", "Religion Theology and Culture 3", "Religion", 0, 5, 0, false, "FWS");

  Class SOSC("SOSC", "Social Science", "Social Science", 0, 4, 0, false, "FWS");

  Class CI1("CI1", "Cultures and Ideas 1", "Culture", 0, 4, 0, false, "FW");

  Class CI2("CI2", "Cultures and Ideas 2", "Culture", 0, 4, 0, false, "WS");

  Class CI3("CI3", "Cultures and Ideas 3", "Culture", 0, 4, 0, false, "FWS");

  Class CE("CE", "Civic Engagement", "Civic Engagement", 0, 4, 0, false, "FWS");

  Classes core;
  core.insert(CTW1);
  core.insert(CTW2);
  core.insert(AW);
  core.insert(ETH);
  core.insert(DIV);
  core.insert(ARTS);
  core.insert(LANG1);
  core.insert(LANG2);
  core.insert(NATSCI);
  core.insert(RTC1);
  core.insert(RTC2);
  core.insert(RTC3);
  core.insert(SOSC);
  core.insert(CI1);
  core.insert(CI2);
  core.insert(CI2);
  core.insert(CE);

  Core coreTest(core);
  coreTest.printCoreDetails();
  coreTest.complete();
  coreTest.markClassFinished("CTW1");
  coreTest.printClassDetails("CTW1");
  coreTest.complete();
}
