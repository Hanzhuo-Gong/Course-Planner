//schedlingAlgorithm.cpp
//split up into multiple cpp class files
//courseID = CS10, course name = "intro to computer science" <-make this CHANGE
//not doing actual classes for the core requirements, just like ARTs or RSOC1 etc.

//CHANGE PREREQUISITES TO A DAG TREE

#include "SchedulingAlgorithm.h"

using namespace Schedule;

void Class::printDetails() {
  cout<<endl;
  cout<<"The classID is "<<classID<<"."<<endl;
  cout<<"The name of the class is "<<name<<"."<<endl;
  cout<<"The subject is "<<subject<<"."<<endl;
  cout<<"The difficulty is "<<difficulty<<"/5."<<endl;
  cout<<"It's worth "<<creditsGiven<<" credits."<<endl;
  cout<<"You need "<<creditsRequired<<" credits before taking this class"<<endl;
  if (preRequisites.empty()==false) {
    cout<<"The prerequisites are ";
    for (int i = 0; i < preRequisites.size(); i++) {
      cout << preRequisites[i];
      if (preRequisiteStates[i]) {
        cout<<" (complete) , ";
      }
      else {
        cout<<" (incomplete) , ";
      }
    }
    cout<<endl;
  }
  else {
    cout<<"This class has no prerequisites"<<endl;
  }
  if (finishedOrNot) {
    cout<<"You've already finished this class."<<endl;
  }
  else {
    cout<<"You have not finished this class."<<endl;
  }
  cout<<endl;
}

Class::Class(int theID, string theName, string theSubject, double theDifficulty, int theCreditsGiven, int theCreditsRequired, vector <string> thePreRequisites, vector <bool> thePreRequisiteStates, bool theState) {
  classID = theID;
  name = theName;
  subject = theSubject;
  difficulty = theDifficulty;
  creditsGiven = theCreditsGiven;
  creditsRequired = theCreditsRequired;
  finishedOrNot = theState;
  for (int i=0 ; i < thePreRequisites.size() ; i++) {
    preRequisites.push_back(thePreRequisites[i]);
    preRequisiteStates.push_back(thePreRequisiteStates[i]);
  }
}

void Classes::insert(Class theClass) {
  classDetails.push_back(theClass);
}

bool Class::getState() {
  return finishedOrNot;
}

string Class::getName() {
  return name;
}

bool Classes::getClassState(int index) {
  classDetails[index].getState();
}

string Classes::getClassName(int index) {
  classDetails[index].getName();
}

Class Classes::getClassDetails(int index) {
  return classDetails[index];
}

void Classes::clear() {
  classDetails.clear();
}

Preferences::Preferences (int theDifficulty, int theClassesPerQuarter, string theExcludedSubjects[100], Classes theExcludedClasses) {
  difficulty = theDifficulty;
  classesPerQuarter = theClassesPerQuarter;
  for (int i=0 ; i < 100 ; i++) {
    excludedSubjects[i] = theExcludedSubjects[i];
  }
  excludedClasses = theExcludedClasses;
}

void Preferences::resetToDefault() {
  difficulty = 0;
  classesPerQuarter = 4;
  for (int i = 0 ; i < 100 ; i++) {
    excludedSubjects[i] = "";
  }
  excludedClasses.clear();
}

int main() {
  vector <string> cs10PreReqs;
  vector <bool> cs10PreReqStates;
  Class CS10 (10000, "CS10", "Computer Science", 0, 5, 0, cs10PreReqs, cs10PreReqStates, 0);
  CS10.printDetails();

  vector <string> cs60PreReqs;
  cs60PreReqs.push_back("CS10");
  vector <bool> cs60PreReqStates;
  cs60PreReqStates.push_back(0);
  Class CS60 (10001, "CS60", "Computer Science", 0, 5, 0, cs60PreReqs, cs60PreReqStates, 0);
  CS60.printDetails();

  vector <string> cs61PreReqs;
  cs61PreReqs.push_back("CS60");
  vector <bool> cs61PreReqStates;
  cs61PreReqStates.push_back(0);
  Class CS61 (10002, "CS61", "Computer Science", 0, 5, 0, cs61PreReqs, cs61PreReqStates, 0);
  CS61.printDetails();

  vector <string> math11PreReqs;
  vector <bool> math11PreReqStates;
  Class MATH11 (10010, "MATH11", "Math", 0, 5, 0, math11PreReqs, math11PreReqStates, 0);
  MATH11.printDetails();

  vector <string> math12PreReqs;
  math12PreReqs.push_back("MATH11");
  vector <bool> math12PreReqStates;
  math12PreReqStates.push_back(0);
  Class MATH12 (10020, "MATH12", "Math", 0, 5, 0, math12PreReqs, math12PreReqStates, 0);
  MATH12.printDetails();

  vector <string> math13PreReqs;
  math13PreReqs.push_back("MATH12");
  vector <bool> math13PreReqStates;
  math13PreReqStates.push_back(0);
  Class MATH13 (10030, "MATH13", "Math", 0, 5, 0, math13PreReqs, math13PreReqStates, 0);
  MATH13.printDetails();

  vector <string> math14PreReqs;
  math14PreReqs.push_back("MATH13");
  vector <bool> math14PreReqStates;
  math14PreReqStates.push_back(0);
  Class MATH14 (10040, "MATH14", "Math", 0, 5, 0, math14PreReqs, math14PreReqStates, 0);
  MATH14.printDetails();
}
