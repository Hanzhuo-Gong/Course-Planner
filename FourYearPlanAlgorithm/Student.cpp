#include "Student.h"

Student::Student(string sID, int y, HashMap prevCompleted) {
  studentID = sID;
  startYear = y;
  previouslyCompletedClasses = prevCompleted;
}

void Student::markPreviouslyCompletedClasses(FourYearPlan &plan) {
  if (previouslyCompletedClasses.getSize()!=0) {
    for (int i = 0 ; i < previouslyCompletedClasses.getSize() ; i ++) {
      plan.completeClass(previouslyCompletedClasses.classIDs[i]);
    }
    cout<<"(Previously completed classes:";
    for (int j = 0 ; j < previouslyCompletedClasses.classIDs.size() ; j++) {
      cout<<" "<<previouslyCompletedClasses.classIDs[j];
    }
    cout<<")"<<endl;
  }
}

void Student::buildPlan(FourYearPlan plan) {
  cout<<"Student "<<studentID<<" Four Year Plan:"<<endl;
  markPreviouslyCompletedClasses(plan);
  plan.buildPlan(startYear);
  cout<<endl;
  plan.printPlan(startYear);
  plan.jsonPrint();
}
