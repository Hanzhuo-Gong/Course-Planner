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
    //cout<<"Set "<<cID<<"to complete."<<endl;
  }
  if (core.containsClass(cID)) {
    finishedClasses.insert(*core.getClass(cID));
    coreClassesFinished++;
    credits+=core.getClass(cID)->getCredits();
    //cout<<"Set "<<cID<<"to complete."<<endl;
  }
  if (requiredEmphasis.containsClass(cID)) {
    finishedClasses.insert(*requiredEmphasis.getClass(cID));
    requiredEmphasisClassesFinished++;
    credits+=requiredEmphasis.getClass(cID)->getCredits();
    //cout<<"Set "<<cID<<"to complete."<<endl;
  }
  if (additionalEmphasis.containsClass(cID)) {
    finishedClasses.insert(*additionalEmphasis.getClass(cID));
    additionalEmphasisClasses++;
    credits+=additionalEmphasis.getClass(cID)->getCredits();
    //cout<<"Set "<<cID<<" to complete."<<endl;
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

  int classCount;
  int quarter = 0;
  int year = 2019;
  int balanceCount = 0;

  while (!planComplete()) {

    classCount = 0;

    balanceCount = 0;

    //cout<<"Checking major HashMap for "<<quarters[quarter]<<year<<endl;
    for (int i = 0 ; i < 14 ; i ++) {
      if (feasible(majorIDs[i], quarters[quarter], year)&&classCount<4) {
        plan[classCount][quarter] = *getClass(majorIDs[i]);
        classCount++;
        balanceCount++;
      }
      if (balanceCount>=2) {
        break;
      }
    }

    balanceCount = 0;

    //cout<<"Checking core HashMap for "<<quarters[quarter]<<year<<endl;
    for (int i = 0 ; i < 17 ; i ++) {
      if (feasible(coreIDs[i], quarters[quarter], year)&&classCount<4) {
        plan[classCount][quarter] = *getClass(coreIDs[i]);
        classCount++;
        balanceCount++;
      }
      if (balanceCount>=2) {
        break;
      }
    }

    balanceCount = 0;

    //cout<<"Checking emphasis HashMaps for "<<quarters[quarter]<<year<<endl;
    for (int i = 0 ; i < 8 ; i ++) {
      if (feasible(emphIDs[i], quarters[quarter], year)&&classCount<4) {
        plan[classCount][quarter] = *getClass(emphIDs[i]);
        classCount++;
        balanceCount++;
      }
      if (balanceCount>=2) {
        break;
      }
    }

    for (int i = 0 ; i < classCount ; i ++) {
        completeClass(plan[i][quarter].getID());
    }
    quarter++;
    if (quarter%3 == 1) {
      year++;
    }
  }
}

void FourYearPlan::printPlan() {
  int year = 2019;
  for (int i = 0 ; i < 12 ; i ++) {
    cout<<quarters[i]<<year<<": ";
    for (int j = 0 ; j < 4 ; j++) {
      cout<<plan[j][i].getID()<<" ";
      // if (plan[j][i].getID()!="") {
      //   plan[j][i].printDetails();
      // }
    }
    cout<<endl;
    if (i%3 == 0) {
      year++;
    }
  }
  cout<<endl;
}

void FourYearPlan::jsonPrint() {
  string years[4] = {"Freshman", "Sophomore", "Junior", "Senior"};
  string quarters[3] = {"Fall", "Winter", "Spring"};
  int quarter = 0 ;
  cout<<"["<<endl; //0 tabs
  int numberOfYears = 4;
  for (int i = 0 ; i < numberOfYears ; i ++) {
    cout<<"  {"<<endl; //1 tab
    cout<<"    \"year\": \""<<years[i]<<"\","<<endl; //2 tabs
    cout<<"    \"yearSchedule\": ["<<endl;
    int numberOfQuarters = 3;
    for (int j = 0 ; j < numberOfQuarters ; j ++) {
      cout<<"      {"<<endl; // 3 tabs
      cout<<"        \"quarter\": \""<<quarters[j]<<"\","<<endl; // 4 tabs
      cout<<"        \"classes\": ["<<endl;
      int numberOfClasses = 4;
      for (int k = 0 ; k < numberOfClasses ; k++) {
        cout<<"          {"<<endl; //5 tabs
        cout<<"            \"name\": \""<<plan[k][quarter].getName()<<"\","<<endl; //6 tabs
        cout<<"            \"prereqs\": ";
        if (plan[k][quarter].preReqs.empty()) {
          cout<<"null"<<endl;;
        }
        else {
          cout<<"["<<endl;
          for (int l = 0 ; l < plan[k][quarter].preReqs.size() ; l++) {
            cout<<"                \""<<plan[k][quarter].preReqs[l]<<"\","<<endl;
          }
          cout<<"            ],"<<endl;
        }
        cout<<"            \"units\": "<<plan[k][quarter].getCredits()/*<<","*/<<endl;
        string endOfClassObject;
        if (k + 1 < numberOfClasses) {
          endOfClassObject = "          },";
        }
        else {
          endOfClassObject = "          }";
        }
        cout<<endOfClassObject<<endl; //5 tabs
      }
      cout<<"        ]"<<endl; //4 tabs
      string endOfQuarterObject;
      if (j + 1 < numberOfQuarters) {
        endOfQuarterObject = "      },";
      }
      else {
        endOfQuarterObject = "      }";
      }
      cout<<endOfQuarterObject<<endl; //3 tabs
      quarter++;
    }
    cout<<"    ]"<<endl; //2 tabs
    string endOfYearObject;
    if (i + 1 < numberOfYears) {
      endOfYearObject = "  },";
    }
    else {
      endOfYearObject = "  }";
    }
    cout<<endOfYearObject<<endl; //1 tab
  }
  cout<<"]"<<endl; //0 tabs
}
