#include "Major.h"

using namespace Schedule;

Major::Major(string majorName, Classes c) {
  major = majorName;
  for (int i = 0 ; i < c.size() ; i++) {
    m.insert(c.classes[i]);
  }
}

bool Major::complete() {
  for (int i = 0 ; i < m.size() ; i++) {
    if (!m.classes[i].getState()) {
      cout<<"Did not complete ";
      for (int j = i ; j < m.size() ; j++) {
        if (!m.classes[j].getState()) {
          cout<<m.classes[j].getID()<<" ";
        }
      }
      cout<<"Major classes incomplete"<<endl;
      return false;
    }
  }
  cout<<"Major classes complete."<<endl;
  return true;
}

void Major::markClassFinished(string classID) {
  int index = m.getClassIndex(classID);
  if (index==-1) {
    cout<<classID<<" not found."<<endl;
  }
  else {
    m.classes[index].setState(true);    
  }
}

void Major::printMajorDetails() {
  cout<<"The major is "<<major<<"."<<endl;
  cout<<"You must take ";
  for (int i = 0 ; i < m.size() ; i ++) {
    cout<<m.classes[i].getID()<<" ";
  }
  cout<<endl;
}

void Major::printClassDetails(string classID) {
  int index = m.getClassIndex(classID);
  if (index==-1) {
    cout<<classID<<" not found."<<endl;
  }
  else {
  m.classes[index].printDetails();
  }
}
