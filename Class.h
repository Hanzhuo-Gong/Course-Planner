#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <vector>

using namespace std;

namespace Schedule {

  class Class {
    public:
      //constructor
      Class(string theID, string theName, string theSubject, double theDifficulty, int theCreditsGiven, int theCreditsRequired, bool theState, string quarters);
      //returns whether or not a class is offered in a certain quarter/year
      bool available(string currentQuarter, int year);
      //returns whether or not it's possible for a student to take a class if all prereqs are complete and you have equal to or more than creditsRequired
      bool feasible(int credits);
      //returns Class ID ex:"CS10"
      string getID();
      //returns Class Name ex:"Intro to Computer Science"
      string getName();
      //returns Class Subject ex: "Computer Science"
      string getSubject();
      //returns difficulty between 0-10, not MVP
      double getDifficulty();
      //returns how many credits a class is WORTH, ex: CS10 = 5 credits
      int getCreditsGiven();
      //returns how many credits you need before taking a class
      int getCreditsRequired();
      //returns whether or not you've finished the class
      bool getState();
      //returns quarters a class is offered ex:FWS = fall winter spring every year, FWSE = fall winter spring in even to odd years like (2018-2019), WSO = winter spring in odd to even years like (2019-2020)
      string getQuarters();
      //pushes a preReq by ID onto the class as well as whether or not it's finished
      void pushPreReq(string cID, bool state);
      //change a pre-existing preReq's state of completion
      void setPreReq(string cID, bool state);
      //change the class's state of completion
      void setState(bool state);
      //print out the class's preReqs
      void printPreReqs();
      //print out all of the class's details
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
