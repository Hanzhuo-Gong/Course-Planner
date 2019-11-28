#ifndef SCUCLASS_H
#define SCUCLASS_H

#include <iostream>
#include <vector>

using namespace std;

class scuClass {
public:
  scuClass();
  scuClass(string cID, string name, string sub, string quart, int creds);
  void pushPreReq(string cID);
  bool available(string q, int year);
  string getID();
  string getName();
  string getSubject();
  string getQuarters();
  int getCredits();
  void printDetails();
  vector <string> preReqs;
private:
  string classID;
  string fullName;
  string subject;
  string quarters;
  int credits;
};

#endif
