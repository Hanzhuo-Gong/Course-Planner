#include "Classes.h"

using namespace Schedule;

int Classes::getClassIndex(string classID) {
  for (int i = 0; i < classes.size(); i++) {
    if (classID == classes[i].getID()) {
      cout<<classID<<" at index "<<i<<"."<<endl;
      return i;
    }
  }
  cout<<classID<<" not found, returned -1."<<endl;
  return -1;
}

bool Classes::getClassState(string classID) {
  int index = getClassIndex(classID);
  if (index!=-1) {
    return classes[index].getState();
  }
  else {
    cout<<"Class not found, returning false."<<endl;
    return false;
  }
}

bool Classes::getClassFeasible(string classID) {
  int index = getClassIndex(classID);
  if (index!=-1) {
    return classes[index].feasible();
  }
  else {
    cout<<"Class not found, returning false."<<endl;
    return false;
  }
}

bool Classes::getClassAvailable(string classID, string quarter, int year) {
  int index = getClassIndex(classID);
  if (index!=-1) {
    return classes[index].available(quarter,year);
  }
  else {
    cout<<"Class not found, returning false."<<endl;
    return false;
  }
}

void Classes::printPreReqs(string classID) {
  int index = getClassIndex(classID);
  if (index!=-1) {
    cout<<"For "<<classID<<" ";
    classes[index].printPreReqs();
  }
  else {
    cout<<"Class not found."<<endl;
  }
}

void Classes::insert(Class c) {
  classes.push_back(c);
}

void Classes::printClassIDs() {
  for (int i = 0; i < classes.size(); i++) {
    cout<<classes[i].getID()<<", ";
  }
}

void Classes::printDetails(string classID) {
  int index = getClassIndex(classID);
  if (index != -1) {
    classes[index].printDetails();
  }
  else {
    cout<<"Class not found."<<endl;
  }
}
