#ifndef FOURYEARPLAN_H
#define FOURYEARPLAN_H

#include "HashMap.h"

class FourYearPlan {
public:
  FourYearPlan(HashMap m, HashMap c, HashMap rE, HashMap tE);
  void completeClass(string cID);
  scuClass* getClass(string cID);
  bool feasible(string cID, string quarter, int year);
  bool planComplete();
  void buildPlan();
  void printPlan();
  void jsonPrint();
private:
  int credits;
  HashMap major;
  int majorClassesFinished;
  HashMap core;
  int coreClassesFinished;
  HashMap requiredEmphasis;
  int requiredEmphasisClassesFinished;
  HashMap additionalEmphasis;
  int additionalEmphasisClasses;
  HashMap finishedClasses;
  scuClass plan[4][12]; //4 classes per quarter, 12 quarters
  string quarters[12] = {"F","W","S","F","W","S","F","W","S","F","W","S"};
  string majorIDs[14] = {"CS10", "CS60", "CS61", "MATH11", "MATH12", "MATH13", "MATH14", "COEN20", "COEN21", "MATH51", "MATH53", "CS161", "CS163A", "MATH122"};
  string coreIDs[17] = {"CTW1", "CTW2", "AW", "ETH", "DIV", "ARTS", "LANG1", "LANG2", "NATSCI", "RTC1", "RTC2", "RTC3", "SOSC", "CI1", "CI2", "CI3", "CE"};
  string emphIDs[8] = {"CS169", "CS187", "COEN146", "CS183", "CS163B", "CS168", "COEN163", "COEN166"};
};

#endif
