#ifndef FOURYEARPLAN_H
#define FOURYEARPLAN_H

#include "HashMap.h"

class FourYearPlan {
public:
  FourYearPlan(HashMap m, HashMap c, HashMap rE, HashMap tE, int creditsAlreadyCompleted);
  void completeClass(string cID);
  scuClass* getClass(string cID);
  bool feasible(string cID, string quarter, int year);
  bool planComplete();
  void buildPlan(int year);
  void printPlan(int year);
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
};

#endif
