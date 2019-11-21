#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <vector>

using namespace std;

namespace Schedule {

  class Class {
    public:
      Class(string theID, string theName, string theSubject, double theDifficulty, int theCreditsGiven, int theCreditsRequired, vector <string> thePreRequisites, vector <bool> thePreRequisiteStates, bool theState, string quarters);
      bool getState();
      bool available(string currentQuarter, int year);
      bool feasible();
      string getID();
      string getName();
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
