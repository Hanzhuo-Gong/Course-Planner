#include "scuClass.h"

scuClass::scuClass() {
  classID = "";
  fullName = "";
  subject = "";
  quarters = "";
  credits = 0;
}

scuClass::scuClass(string cID, string name, string sub, string quart, int creds) {
  classID = cID;
  fullName = name;
  subject = sub;
  quarters = quart;
  credits = creds;
}

void scuClass::pushPreReq(string cID) {
  preReqs.push_back(cID);
}

bool scuClass::available(string q, int year) {
  if (year%2==0) {
  if (quarters[quarters.size()-1]!='O') {
    for (int i = 0; i < quarters.size(); i++) {
      if (q[0] == quarters[i]) {
        //cout<<classID<<" is available in "<<q<<", "<<year<<"."<<endl;
        return true;
      }
    }
  }
}
else {
  if (quarters[quarters.size()-1]!='E') {
    for (int i = 0; i < quarters.size(); i++) {
      if (q[0] == quarters[i]) {
        //cout<<classID<<" is available in "<<q<<", "<<year<<"."<<endl;
        return true;
      }
    }
  }
}
//cout<<classID<<" is not available in "<<q<<", "<<year<<"."<<endl;
return false;
}

string scuClass::getID() {
  return classID;
}

string scuClass::getName() {
  return fullName;
}

string scuClass::getSubject() {
  return subject;
}

string scuClass::getQuarters() {
  return quarters;
}

int scuClass::getCredits() {
  return credits;
}

void scuClass::printDetails() {
  cout<<endl;
  cout<<"Class ID: "<<classID<<endl;
  cout<<"Name: "<<fullName<<endl;
  cout<<"Subject: "<<subject<<endl;
  cout<<"Credits: "<<credits<<endl;
  cout<<"Offered:";

  switch (quarters[quarters.size()-1]) {
    case 'E': cout<<" even school years (ex: 2018-2019, 2020-2021, NOT 2019-2020) ";
    break;
    case 'O': cout<<" odd school years (ex: 2019-2020, 2021-2022, NOT 2020-2021) ";
    break;
    default: cout<<" every year ";
    break;
  }

  cout<<"during ";
  for (int i = 0; i < quarters.size() ; i++) {
    if (quarters[i]=='F') {
      cout<<"Fall ";
    }
    if (quarters[i]=='W') {
      cout<<"Winter ";
    }
    if (quarters[i]=='S') {
      cout<<"Spring ";
    }
  }

  cout<<endl;

  if (preReqs.empty()==false) {
    cout<<"PreReqs: ";
    for (int i = 0; i < preReqs.size(); i++) {
      cout << preReqs[i]<<" ";
    }
    cout<<endl;
  }
  else {
    cout<<"No PreReqs."<<endl;
  }
}
