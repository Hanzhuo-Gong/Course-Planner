#include "Class.h"

using namespace Schedule;

Class::Class(string theID, string theName, string theSubject, double theDifficulty, int theCreditsGiven, int theCreditsRequired, bool theState, string quarters) {
  classID = theID;
  name = theName;
  subject = theSubject;
  difficulty = theDifficulty;
  creditsGiven = theCreditsGiven;
  creditsRequired = theCreditsRequired;
  finished = theState;
  quartersOffered = quarters;
  // for (int i=0 ; i < thePreRequisites.size() ; i++) {
  //   preRequisites.push_back(thePreRequisites[i]);
  //   preRequisiteStates.push_back(thePreRequisiteStates[i]);
  // }
}

bool Class::available(string currentQuarter, int year) {
  if (year%2==0) {
    if (quartersOffered[quartersOffered.size()-1]!='O') {
      for (int i = 0; i < quartersOffered.size(); i++) {
        if (currentQuarter[0] == quartersOffered[i]) {
          cout<<classID<<" is available in "<<currentQuarter<<", "<<year<<"."<<endl;
          return true;
        }
      }
    }
  }
  else {
    if (quartersOffered[quartersOffered.size()-1]!='E') {
      for (int i = 0; i < quartersOffered.size(); i++) {
        if (currentQuarter[0] == quartersOffered[i]) {
          cout<<classID<<" is available in "<<currentQuarter<<", "<<year<<"."<<endl;
          return true;
        }
      }
    }
  }
  cout<<classID<<" is not available in "<<currentQuarter<<", "<<year<<"."<<endl;
  return false;
}

bool Class::feasible(int credits) {
  if (finished) {
    cout<<classID<<" is not feasible, it's already been finished."<<endl;
    return false;
  }

  if (credits < creditsRequired) {
    cout<<"Not enough credits, need at least "<<creditsRequired-credits<<" more."<<endl;
    return false;
  }

  for (int i = 0; i < preRequisiteStates.size(); i++) {
    if (!preRequisiteStates[i]) {
      cout<<classID<<" is not feasible, still need to complete ";
      for (int j = i ; j < preRequisiteStates.size() ; j ++) {
        if (!preRequisiteStates[j]) {
          cout<<preRequisites[j]<<" ";
        }
      }
      cout<<endl;
      return false;
    }
    // if (finished) {
    //   cout<<classID<<" is not feasible, it's already been finished."<<endl;
    //   return false;
    // }
  }

  cout<<classID<<" is feasible."<<endl;
  return true;
}

string Class::getID() {
  return classID;
}

string Class::getName() {
  return name;
}

string Class::getSubject() {
  return subject;
}

double Class::getDifficulty() {
  return difficulty;
}

int Class::getCreditsGiven() {
  return creditsGiven;
}

int Class::getCreditsRequired() {
  return creditsRequired;
}

bool Class::getState() {
  return finished;
}

string Class::getQuarters() {
  return quartersOffered;
}

void Class::pushPreReq(string cID, bool state) {
  preRequisites.push_back(cID);
  preRequisiteStates.push_back(state);
}

void Class::setPreReq(string cID, bool state) {
  for (int i = 0 ; i < preRequisites.size() ; i++) {
    if (preRequisites[i] == cID) {
      preRequisiteStates[i] = state;
      if (state) {
        cout<<preRequisites[i]<<" has been set to complete."<<endl;
        return;
      }
      else {
        cout<<preRequisites[i]<<"has been set to incomplete."<<endl;
        return;
      }
    }
  }
  cout<<"The class is not a PreReq of "<<classID<<"."<<endl;
}

void Class::setState(bool state) {
  finished = state;
}

void Class::printPreReqs() {
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
}

void Class::printDetails() {
  cout<<endl;

  cout<<"The classID is "<<classID<<"."<<endl;
  cout<<"The name of the class is "<<name<<"."<<endl;
  cout<<"The subject is "<<subject<<"."<<endl;
  cout<<"The difficulty is "<<difficulty<<"/5."<<endl;
  cout<<"It's worth "<<creditsGiven<<" credits."<<endl;
  cout<<"You need "<<creditsRequired<<" credits before taking this class"<<endl;

  cout<<"This course is offered ";

  switch (quartersOffered[quartersOffered.size()-1]) {
    case 'E': cout<<"in even school years (ex: 2018-2019, 2020-2021, NOT 2019-2020) ";
    break;
    case 'O': cout<<"in odd school years (ex: 2019-2020, 2021-2022, NOT 2020-2021) ";
    break;
    default: cout<<"every year ";
    break;
  }

  cout<<"during ";
  for (int i = 0; i < quartersOffered.size() ; i++) {
    if (quartersOffered[i]=='F') {
      cout<<"Fall ";
    }
    if (quartersOffered[i]=='W') {
      cout<<"Winter ";
    }
    if (quartersOffered[i]=='S') {
      cout<<"Spring ";
    }
  }

  cout<<endl;

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

  if (finished) {
    cout<<"You've already finished this class."<<endl;
  }
  else {
    cout<<"You have not finished this class."<<endl;
  }

  cout<<endl;
}
