#include "FourYearPlan.h"

int main() {
  scuClass CS10 ("CS10", "Intro to Computer Science", "Computer Science", "FWS", 5);
  //CS10.printDetails();

  scuClass CS60 ("CS60", "Object-Oriented Programming", "Computer Science",  "WS", 5);
  CS60.pushPreReq("CS10");
  //CS60.printDetails();

  scuClass CS61 ("CS61", "Data Structures", "Computer Science", "FS", 5);
  CS61.pushPreReq("CS60");
  //CS61.printDetails();

  scuClass MATH11 ("MATH11", "Calculus and Analytic Geometry I", "Math", "FWS", 5);
  //MATH11.printDetails();

  scuClass MATH12 ("MATH12", "Calculus and Analytic Geometry II", "Math", "FWS", 5);
  MATH12.pushPreReq("MATH11");
  //MATH12.printDetails();

  scuClass MATH13 ("MATH13", "Calculus and Analytic Geometry III", "Math", "FWS", 5);
  MATH13.pushPreReq("MATH12");
  //MATH13.printDetails();

  scuClass MATH14 ("MATH14", "Calculus and Analytic Geometry IV", "Math", "FWS", 5);
  MATH14.pushPreReq("MATH13");
  //MATH14.printDetails();

  scuClass COEN20 ("COEN20", "Intro to Embedded Systems", "Computer Engineering", "FWS", 5);
  COEN20.pushPreReq("CS60");

  scuClass COEN21 ("COEN21", "Intro to Logic Design", "Computer Engineering", "FWS", 5);

  scuClass MATH51 ("MATH51", "Discrete Mathematics", "Math", "FWS", 5);

  scuClass MATH53 ("MATH53", "Linear Algebra", "Math", "FWS", 4);
  MATH53.pushPreReq("MATH13");

  scuClass CS161 ("CS161", "Theory of Automata and Languages 1", "Computer Science", "FW", 5);
  CS161.pushPreReq("MATH51");

  scuClass CS163A ("CS163A", "Theory of Algorithms", "Computer Science", "FWS", 5);
  CS163A.pushPreReq("MATH51");
  CS163A.pushPreReq("CS61");
  //CS163A.printDetails();

  scuClass MATH122 ("MATH122", "Probability and Statistics 1", "Math", "FW", 5);
  MATH122.pushPreReq("MATH14");

  HashMap major; //hash function rewritten to flip negatives to positives
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

  scuClass CTW1 ("CTW1", "Critical Thinking and Writing 1", "English", "FW", 4);

  scuClass CTW2 ("CTW2", "Critical Thinking and Writing 2", "English", "WS", 4);
  CTW2.pushPreReq("CTW1");

  scuClass AW("AW", "Advanced Writing", "English", "FWS", 5);
  AW.pushPreReq("CTW2");

  scuClass ETH("ETH", "Ethics", "Ethics", "FWS", 5);

  scuClass DIV("DIV", "Diversity", "Diversity", "FWS", 5);

  scuClass ARTS("ARTS", "Arts", "Arts", "FWS", 4);

  scuClass LANG1("LANG1", "Foreign Language 1", "Foreign Language", "FWS", 4);

  scuClass LANG2("LANG2", "Foreign Language 2", "Foreign Language", "FWS", 4);

  scuClass NATSCI ("NATSCI", "Natural Science", "Natural Science", "FWS", 5);

  scuClass RTC1("RTC1", "Religion Theology and Culture 1", "Religion", "FWS", 4);

  scuClass RTC2("RTC2", "Religion Theology and Culture 2", "Religion", "FWS", 4);

  scuClass RTC3("RTC3", "Religion Theology and Culture 3", "Religion", "FWS", 5);

  scuClass SOSC("SOSC", "Social Science", "Social Science", "FWS", 4);

  scuClass CI1("CI1", "Cultures and Ideas 1", "Culture", "FW", 4);

  scuClass CI2("CI2", "Cultures and Ideas 2", "Culture", "WS", 4);

  scuClass CI3("CI3", "Cultures and Ideas 3", "Culture", "FWS", 4);

  scuClass CE("CE", "Civic Engagement", "Civic Engagement", "FWS", 4);

  HashMap core;
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
  core.insert(CI3);
  core.insert(CE);

  scuClass CS169 ("CS169", "Programming Languages", "Computer Science", "S", 5);
  CS169.pushPreReq("CS61");
  CS169.pushPreReq("MATH51");

  scuClass CS187 ("CS187", "Design Management of Software", "Computer Science", "F", 5);
  CS187.pushPreReq("CS61");

  scuClass COEN146 ("COEN146", "Computer Networks", "Computer Engineering", "FWS", 5);
  COEN146.pushPreReq("CS61");

  HashMap softwareReqEmphasis;
  softwareReqEmphasis.insert(CS169);
  softwareReqEmphasis.insert(CS187);
  softwareReqEmphasis.insert(COEN146);

  scuClass CS183 ("CS183", "Data Science", "Computer Science", "WS", 5);
  CS183.pushPreReq("CS61");
  CS183.pushPreReq("MATH53");
  CS183.pushPreReq("MATH122");

  scuClass CS163B ("CS163B", "Advanced Algorithms", "Computer Science", "W", 5);
  CS163B.pushPreReq("CS163A");

  scuClass CS168 ("CS168", "Computer Graphics", "Computer Science", "F", 5);
  CS168.pushPreReq("CS10");
  CS168.pushPreReq("MATH13");

  scuClass COEN163 ("COEN163", "Web Usability", "Computer Engineering", "FWS", 5);
  COEN163.pushPreReq("CS61");

  scuClass COEN166 ("COEN166", "Artificial Intelligience", "Computer Engineering", "FS", 5);
  COEN166.pushPreReq("CS61");
  COEN166.pushPreReq("MATH51");

  HashMap softwareTwoMoreEmphasis;
  softwareTwoMoreEmphasis.insert(CS183);
  softwareTwoMoreEmphasis.insert(CS163B);
  softwareTwoMoreEmphasis.insert(CS168);
  softwareTwoMoreEmphasis.insert(COEN163);
  softwareTwoMoreEmphasis.insert(COEN166);

  FourYearPlan p(major, core, softwareReqEmphasis, softwareTwoMoreEmphasis);
  p.buildPlan();
  p.printPlan();
}
