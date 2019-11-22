#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <vector>

using namespace std;

namespace Schedule {

  class Class {
    public:
      Class(string theID, string theName, string theSubject, double theDifficulty, int theCreditsGiven, int theCreditsRequired, bool theState, string quarters);
      bool available(string currentQuarter, int year);
      bool feasible();
      string getID();
      string getName();
      string getSubject();
      double getDifficulty();
      int getCreditsGiven();
      int getCreditsRequired();
      bool getState();
      string getQuarters();
      void pushPreReq(string cID, bool state);
      void setPreReq(string cID, bool state);
      void setState(bool state);
      void printPreReqs();
      void printDetails();
    private:
      string classID;
      string name;
      string subject;
      double difficulty;
      int creditsGiven;
      int creditsRequired;
      bool finished;
      string quartersOffered;
      vector <string> preRequisites;
      vector <bool> preRequisiteStates;
  };

}

#endif
