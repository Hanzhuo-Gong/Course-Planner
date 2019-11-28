#include "FourYearPlan.h"

FourYearPlan::FourYearPlan(HashMap m, HashMap c, HashMap rE, HashMap tE) {
  major = m;
  core = c;
  requiredEmphasis = rE;
  additionalEmphasis = tE;
  credits = 0;
  majorClassesFinished = 0;
  coreClassesFinished = 0;
  requiredEmphasisClassesFinished = 0;
  additionalEmphasisClasses = 0;
  // cout<<"constructed."<<endl;
}

void FourYearPlan::completeClass(string cID) {
  if (major.containsClass(cID)) {
    finishedClasses.insert(*major.getClass(cID));
    majorClassesFinished++;
    credits+=major.getClass(cID)->getCredits();
  }
  if (core.containsClass(cID)) {
    finishedClasses.insert(*core.getClass(cID));
    coreClassesFinished++;
    credits+=core.getClass(cID)->getCredits();
  }
  if (requiredEmphasis.containsClass(cID)) {
    finishedClasses.insert(*requiredEmphasis.getClass(cID));
    requiredEmphasisClassesFinished++;
    credits+=requiredEmphasis.getClass(cID)->getCredits();
  }
  if (additionalEmphasis.containsClass(cID)) {
    finishedClasses.insert(*additionalEmphasis.getClass(cID));
    additionalEmphasisClasses++;
    credits+=additionalEmphasis.getClass(cID)->getCredits();
  }
}

scuClass* FourYearPlan::getClass(string cID) {
  if (major.containsClass(cID)) {
    return major.getClass(cID);
  }
  if (core.containsClass(cID)) {
    return core.getClass(cID);
  }
  if (requiredEmphasis.containsClass(cID)) {
    return requiredEmphasis.getClass(cID);
  }
  if (additionalEmphasis.containsClass(cID)) {
    return additionalEmphasis.getClass(cID);
  }
}

bool FourYearPlan::feasible(string cID, string quarter, int year) {

  if (finishedClasses.containsClass(cID)) {
    return false;
  }

  for (int i = 0; i < getClass(cID)->preReqs.size() ; i++) {
    if (!finishedClasses.containsClass(getClass(cID)->preReqs[i])) {
      return false;
    }
  }

  return getClass(cID)->available(quarter, year);

}

bool FourYearPlan::planComplete() {
  if (majorClassesFinished==major.getSize()&&coreClassesFinished==core.getSize()&&requiredEmphasisClassesFinished==requiredEmphasis.getSize()&&additionalEmphasisClasses>=2) {
    return true;
  }
  else {
    return false;
  }
}

void FourYearPlan::buildPlan() {
  int classCount = 0;
  //int quarterCount = 0;
  int quarter = 0;
  int year = 2019;
  int balanceCount = 0;
  while (!planComplete()) {

    classCount = 0;

    balanceCount = 0;
    cout<<"Checking major HashMap for "<<quarters[quarter]<<year<<endl;
    for (int i = 0 ; i < 14 ; i ++) {
      if (feasible(majorIDs[i], quarters[quarter], year)&&classCount<4) {
        completeClass(majorIDs[i]);
        plan[classCount][quarter] = *getClass(majorIDs[i]);
        classCount++;
        balanceCount++;
      }
      if (balanceCount>=2) {
        break;
      }
    }

    balanceCount = 0;
    cout<<"Checking core HashMap for "<<quarters[quarter]<<year<<endl;
    for (int i = 0 ; i < 17 ; i ++) {
      if (feasible(coreIDs[i], quarters[quarter], year)&&classCount<4) {
        completeClass(coreIDs[i]);
        plan[classCount][quarter] = *getClass(coreIDs[i]);
        classCount++;
        balanceCount++;
      }
      if (balanceCount>=2) {
        break;
      }
    }

    balanceCount = 0;
    cout<<"Checking emphasis HashMaps for "<<quarters[quarter]<<year<<endl;
    for (int i = 0 ; i < 8 ; i ++) {
      if (feasible(emphIDs[i], quarters[quarter], year)&&classCount<4) {
        completeClass(emphIDs[i]);
        plan[classCount][quarter] = *getClass(emphIDs[i]);
        classCount++;
        balanceCount++;
      }
    }
    quarter++;
    if (quarter%3 == 0) {
      year++;
    }
  }
}

void FourYearPlan::printPlan() {
  int year = 2019;
  for (int i = 0 ; i < 12 ; i ++) {
    cout<<quarters[i]<<year<<": ";
    for (int j = 0 ; j < 4 ; j++) {
      cout<<plan[i][j].getID()<<" ";
    }
    cout<<endl;
    if (i%3 == 0 && i != 0) {
      year++;
    }
  }
}
