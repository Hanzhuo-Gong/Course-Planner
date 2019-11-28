#include "FourYearPlan.h"

FourYearPlan::FourYearPlan(HashMap m, HashMap c, HashMap rE, HashMap tE, int creditsAlreadyCompleted) {
  major = m;
  core = c;
  requiredEmphasis = rE;
  additionalEmphasis = tE;
  credits = creditsAlreadyCompleted;
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
  if (majorClassesFinished>=major.getSize()&&coreClassesFinished>=core.getSize()/*&&requiredEmphasisClassesFinished>=requiredEmphasis.getSize()*/&&additionalEmphasisClasses>=2&&credits>=175) {
    return true;
  }
  else {
/*
    cout << "major classes finished: " << majorClassesFinished << endl;
    cout << "major hashmap size: " << major.getSize() << endl;
    cout << "core classes finished: " << coreClassesFinished << endl;
    cout << "core hashmap size: " << core.getSize() << endl;
    cout << "emphases finished: " << requiredEmphasisClassesFinished << endl;
    cout << "emphases hashmap size: " << requiredEmphasis.getSize() << endl;
    cout << "additional emphases: " << additionalEmphasisClasses << endl;
*/
    cout << "credits: " << credits << endl;
    return false;
  }
}

void FourYearPlan::buildPlan(int year) {

  int classCount;
  int quarter = 0;
  int balanceCount;

  while (!planComplete()) {

    classCount = 0;

    balanceCount = 0;
/*
    if (quarter < 30 ) {
        cout<<"Checking major HashMap for "<<quarters[quarter]<<year<<endl;
    }
*/
    for (int i = 0 ; i < major.classIDs.size() ; i ++) {
      if (feasible(major.classIDs[i], quarters[quarter], year)&&classCount<4) {
        plan[classCount][quarter] = *getClass(major.classIDs[i]);
        classCount++;
        balanceCount++;
      }
      if (balanceCount>=2) {
        break;
      }
    }
//    cout << "break1" << endl;
    for (int i = 0 ; i < requiredEmphasis.classIDs.size() ; i ++) {
      if (balanceCount>=2) {
        break;
      }
      if (feasible(requiredEmphasis.classIDs[i], quarters[quarter], year)&&classCount<4) {
        plan[classCount][quarter] = *getClass(requiredEmphasis.classIDs[i]);
        classCount++;
        balanceCount++;
      }
    }
//    cout << "break2" << endl;
    for (int i = 0 ; i < additionalEmphasis.classIDs.size() ; i ++) {
      if (balanceCount>=2) {
        break;
      }
      if (feasible(additionalEmphasis.classIDs[i], quarters[quarter], year)&&classCount<4) {
        plan[classCount][quarter] = *getClass(additionalEmphasis.classIDs[i]);
        classCount++;
        balanceCount++;
      }
    }

    balanceCount = 0;

    //cout<<"Checking core HashMap for "<<quarters[quarter]<<year<<endl;
    for (int i = 0 ; i < core.classIDs.size() ; i ++) {
      if (feasible(core.classIDs[i], quarters[quarter], year)&&classCount<4) {
        plan[classCount][quarter] = *getClass(core.classIDs[i]);
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

void FourYearPlan::printPlan(int year) {
  for (int i = 0 ; i < 12 ; i ++) {
    cout<<quarters[i]<<year<<": ";
    for (int j = 0 ; j < 4 ; j++) {
      cout<<plan[j][i].getID()<<" ";
    }
    cout<<endl;
    if (i%3 == 0) {
      year++;
    }
  }
  cout<<"Total credits: "<<credits<<"."<<endl<<endl;
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
        // use getName() if you want full name of class
        cout<<"            \"name\": \""<<plan[k][quarter].getID()<<"\","<<endl; //6 tabs
        cout<<"            \"prereqs\": ";
        if (plan[k][quarter].preReqs.empty()) {
          cout<<"null,"<<endl;;
        }
        else {
          cout<<"["<<endl;
          int numberOfPreReqs = plan[k][quarter].preReqs.size();
          for (int l = 0 ; l < numberOfPreReqs ; l++) {
            cout<<"                \""<<plan[k][quarter].preReqs[l]<<"\"";
            if (l + 1 < numberOfPreReqs) {
              cout<<",";
            }
            cout<<endl;
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
