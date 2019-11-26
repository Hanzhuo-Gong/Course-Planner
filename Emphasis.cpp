#include "Emphasis.h"

using namespace Schedule;

Emphasis::Emphasis(string e, Classes req, Classes two) {
  emphasis = e;
  for (int i = 0 ; i < req.size() ; i++) {
    required.insert(req.classes[i]);
  }
  for (int j = 0 ; j < two.size() ; j++) {
    twoMore.insert(two.classes[j]);
  }
}

bool Emphasis::requiredComplete() {
  for (int i = 0 ; i < required.size() ; i++) {
    if (!required.classes[i].getState()) {
      cout<<"Did not complete ";
      for (int j = i ; j < required.size() ; j++) {
        if (!required.classes[j].getState()) {
          cout<<required.classes[j].getID()<<" ";
        }
      }
      cout<<endl;
      cout<<"Required Emphasis classes incomplete"<<endl;
      return false;
    }
  }
  cout<<"Required Emphasis classes complete."<<endl;
  return true;
}

bool Emphasis::twoMoreComplete() {
  int count=0;
  for (int i = 0 ; i < twoMore.size() ; i++) {
    if (twoMore.classes[i].getState()) {
      count++;
    }
  }
  if (count < 2) {
    cout<<"You still need to take "<<2-count<<" more upper division upper-division CSCI or COEN courses."<<endl;
    cout<<"Additional Upper Divs incomplete."<<endl;
    return false;
  }
  else {
    cout<<"Additional Upper Divs complete."<<endl;
    return true;
  }
}

bool Emphasis::complete() {
  if (requiredComplete()&&twoMoreComplete()) {
    cout<<"Emphasis complete."<<endl;
    return true;
  }
  else {
    cout<<"Emphasis incomplete."<<endl;
    return false;
  }
}

void Emphasis::markClassFinished(string classID) {
  int index = required.getClassIndex(classID);
  if (index == -1) {
    index = twoMore.getClassIndex(classID);
    if (index == -1) {
      cout<<classID<<" not found."<<endl;
    }
    else {
      twoMore.classes[index].setState(true);
    }
  }
  else {
    required.classes[index].setState(true);
  }
}

void Emphasis::printEmphasisDetails() {
  cout<<"The Emphasis is "<<emphasis<<"."<<endl;
  cout<<"You must take ";
  for (int i = 0 ; i < required.size() ; i ++) {
    cout<<required.classes[i].getID()<<" ";
  }
  cout<<endl;
  cout<<"You also must take two courses from: ";
  for (int j = 0 ; j < twoMore.size() ; j ++) {
    cout<<twoMore.classes[j].getID()<<" ";
  }
  cout<<endl;
}

void Emphasis::printClassDetails(string classID) {
  int index = required.getClassIndex(classID);
  if (index == -1) {
    index = twoMore.getClassIndex(classID);
    if (index == -1) {
      cout<<classID<<" not found."<<endl;
    }
    else {
      twoMore.classes[index].printDetails();
    }
  }
  else {
    required.classes[index].printDetails();
  }
}
