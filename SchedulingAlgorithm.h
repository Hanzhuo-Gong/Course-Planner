//SchedulingAlgorithm.h

#ifndef SCHEDULING_ALGORITHM_H
#define SCHEDULING_ALGORITHM_H

#include <iostream>
#include <vector>
using namespace std;

namespace Schedule
{

  class Class {
    public:
      Class(int theID, string theName, string theSubject, double theDifficulty, int theCreditsGiven, int theCreditsRequired, vector <string> thePreRequisites, vector <bool> thePreRequisiteStates, bool theState);
      bool getState();
      string getName();
      void printDetails();
    private:
      int classID;
      string name;
      string subject;
      double difficulty;
      int creditsGiven;
      int creditsRequired;
      bool finishedOrNot;
      vector <string> preRequisites;
      vector <bool> preRequisiteStates;
  };

  class Classes {
  public:
    void setNames();
    void insert(Class theClass);
    bool getClassState(int index);
    Class getClassDetails(int index);
    string getClassName(int index);
    void clear();
  private:
    vector <Class> classDetails;
  };

  class Preferences {
    public:
      Preferences (int theDifficulty, int theClassesPerQuarter, string theExcludedSubjects[100], Classes theExcludedClasses);
      void resetToDefault();
    private:
      int difficulty;
      int classesPerQuarter;
      string excludedSubjects[100];
      Classes excludedClasses;
  };

  class Major {
    public:
      int getCredits();
      double getRequiredGPA();
      void setRequiredMajorClasses();
    private:
      int requiredCredits;
      double requiredGPA;
      Classes requiredMajorClasses;
  };

  class Emphasis {
  public:
    void setEmphasis();
    string getEmphasis();
    void setRequiredEmphasisClasses();
    void setElectiveEmphasisClasses();
  private:
    string emphasis;
    Classes requiredEmphasisClasses;
    Classes electiveEmphasisClasses;
  };

  class Core {
    public:
      void setSubjects();
      void setRequiredGPA();
      void setRequiredCredits();
      void setRequiredUpperCredits();
      void setCoreClasses();
      double getGPA();
      int getRequiredCredits();
      int getUpperRequiredCredits();
    private:
      string requiredSubjects[100];
      double requiredGPA;
      int requiredCredits;
      int requiredUpperCredits;
      Classes allCoreClasses;
  };

  class FourYearPlan {
    public:
      void updateCompleteness();
      void updateCredits();
      void printPlan();
      void updateAllClasses();
      void updateFeasibleSet();
      void updateCombinationSet();
      void forwardSearch();
      void backwardInduction();
    private:
      int quarters = 20; //few extra just in case
      int currentCredits;
      int remainingCredits;
      Emphasis theEmphasis;
      Major theMajor;
      Core theCore;
      Classes allClasses;
      Classes feasibleClasses;
      Classes availableClasses[20];
      Classes chosenClasses[20];

  };

  class Student {
  public:
    void setAll();
    void generatePlan();
  private:
    int studentID;
    string name;
    string major;
    string emphasis;
    int credits;
    Preferences thePreferences;
    FourYearPlan thePlan;
  };

}

#endif
