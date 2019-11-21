#include "Class.h"

using namespace Schedule;

Class::Class(string theID, string theName, string theSubject, double theDifficulty, int theCreditsGiven, int theCreditsRequired, vector <string> thePreRequisites, vector <bool> thePreRequisiteStates, bool theState, string quarters) {
  classID = theID;
  name = theName;
  subject = theSubject;
  difficulty = theDifficulty;
  creditsGiven = theCreditsGiven;
  creditsRequired = theCreditsRequired;
  finished = theState;
  quartersOffered = quarters;
  for (int i=0 ; i < thePreRequisites.size() ; i++) {
    preRequisites.push_back(thePreRequisites[i]);
    preRequisiteStates.push_back(thePreRequisiteStates[i]);
  }
}

bool Class::getState() {
  return finished;
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

bool Class::feasible() {
  for (int i = 0; i < preRequisiteStates.size(); i++) {
    if (!preRequisiteStates[i]) {
      cout<<classID<<" is not feasible."<<endl;
      return false;
    }
  }
  cout<<classID<<" is feasible."<<endl;
  return true;
}

string Class::getName() {
  return name;
}

string Class::getID() {
  return classID;
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

int main() {
  vector <string> cs10PreReqs;
  vector <bool> cs10PreReqStates;
  Class CS10 ("CS10", "Intro to Computer Science", "Computer Science", 0, 5, 0, cs10PreReqs, cs10PreReqStates, 0, "FWS");
  CS10.printDetails();

  vector <string> cs60PreReqs;
  cs60PreReqs.push_back("CS10");
  vector <bool> cs60PreReqStates;
  cs60PreReqStates.push_back(0);
  Class CS60 ("CS60", "Object-Oriented Programming", "Computer Science", 0, 5, 0, cs60PreReqs, cs60PreReqStates, 0, "WS");
  CS60.printDetails();

  vector <string> cs61PreReqs;
  cs61PreReqs.push_back("CS60");
  vector <bool> cs61PreReqStates;
  cs61PreReqStates.push_back(0);
  Class CS61 ("CS61", "Data Structures", "Computer Science", 0, 5, 0, cs61PreReqs, cs61PreReqStates, 0, "FS");
  CS61.printDetails();

  vector <string> math11PreReqs;
  vector <bool> math11PreReqStates;
  Class MATH11 ("MATH11", "Calculus and Analytic Geometry I", "Math", 0, 5, 0, math11PreReqs, math11PreReqStates, 0, "FWS");
  MATH11.printDetails();

  vector <string> math12PreReqs;
  math12PreReqs.push_back("MATH11");
  vector <bool> math12PreReqStates;
  math12PreReqStates.push_back(0);
  Class MATH12 ("MATH12", "Calculus and Analytic Geometry II", "Math", 0, 5, 0, math12PreReqs, math12PreReqStates, 0, "FWS");
  MATH12.printDetails();

  vector <string> math13PreReqs;
  math13PreReqs.push_back("MATH12");
  vector <bool> math13PreReqStates;
  math13PreReqStates.push_back(0);
  Class MATH13 ("MATH13", "Calculus and Analytic Geometry III", "Math", 0, 5, 0, math13PreReqs, math13PreReqStates, 0, "FWS");
  MATH13.printDetails();

  vector <string> math14PreReqs;
  math14PreReqs.push_back("MATH13");
  vector <bool> math14PreReqStates;
  math14PreReqStates.push_back(1);
  Class MATH14 ("MATH14", "Calculus and Analytic Geometry IV", "Math", 0, 5, 0, math14PreReqs, math14PreReqStates, 0, "FWS");
  MATH14.printDetails();
  MATH14.feasible();

  vector <string> cs163aPreReqs;
  cs163aPreReqs.push_back("MATH51");
  cs163aPreReqs.push_back("CS61");
  vector <bool> cs163aPreReqStates;
  cs163aPreReqStates.push_back(0);
  cs163aPreReqStates.push_back(0);
  Class CS163A ("CS163A", "Theory of Algorithms", "Computer Science", 0, 5, 0, cs163aPreReqs, cs163aPreReqStates, 0, "FWS");
  CS163A.printDetails();
  CS163A.feasible();

  vector <string> cs165PreReqs;
  vector <bool> cs165PreReqStates;
  Class CS165 ("CS165", "Linear Programming", "Computer Science", 0, 5, 0, cs165PreReqs, cs165PreReqStates, 0, "WO");
  CS165.printDetails();
  CS165.available("Winter", 2020);
  CS165.available("Fall", 2021);
  CS165.available("Winter", 2021);

}
