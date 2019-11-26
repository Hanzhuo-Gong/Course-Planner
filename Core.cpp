#include "Core.h"

using namespace Schedule;

Core::Core(Classes core) {
  for (int i = 0 ; i < core.size() ; i++) {
    c.insert(core.classes[i]);
  }
}

bool Core::complete() {
  for (int i = 0 ; i < c.size() ; i++) {
    if (!c.classes[i].getState()) {
      cout<<"Did not complete ";
      for (int j = i ; j < c.size() ; j++) {
        if (!c.classes[j].getState()) {
          cout<<c.classes[j].getID()<<" ";
        }
      }
      cout<<"Core classes incomplete"<<endl;
      return false;
    }
  }
  cout<<"Core classes complete."<<endl;
  return true;
}

void Core::markClassFinished(string classID) {
  int index = c.getClassIndex(classID);
  c.classes[index].setState(true);
}

void Core::printCoreDetails() {
  cout<<"You must take these SCU Core Classes: ";
  for (int i = 0 ; i < c.size() ; i++) {
    cout<<c.classes[i].getID()<<" ";
  }
  cout<<endl;
}

void Core::printClassDetails(string classID) {
  int index = c.getClassIndex(classID);
  if (index==-1) {
    cout<<classID<<" not found."<<endl;
  }
  else {
  c.classes[index].printDetails();
  }
}
