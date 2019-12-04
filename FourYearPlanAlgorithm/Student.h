#ifndef STUDENT_H
#define STUDENT_H

#include "FourYearPlan.h"

class Student {
public:
  Student(string sID, int y, HashMap prevCompleted);
  void markPreviouslyCompletedClasses(FourYearPlan &plan);
  void buildPlan(FourYearPlan plan);
private:
  int startYear;
  string studentID;
  HashMap previouslyCompletedClasses;
};

#endif
