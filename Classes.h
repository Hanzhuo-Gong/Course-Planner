#ifndef CLASSES_H
#define CLASSES_H

#include "Class.h"

namespace Schedule {
  class Classes {
  public:
    //no constructor because you're meant to declare then insert data

    //returns which index a class is at in the set, returns -1 if it's not there, this is used many times in the functions below
    int getClassIndex(string classID);
    //returns number of classes in set
    int size();
    //returns state of class in set by ID, if not there returns false
    bool getClassState(string classID);
    //returns whether class in set is feasible, if not there returns false
    bool getClassFeasible(string classID, int credits);
    //returns whether class in set is available, if not there returns false
    bool getClassAvailable(string classID, string quarter, int year);
    //prints prereqs of a class in set if found
    void printPreReqs(string classID);
    //inserts Class into set
    void insert(Class c);
    //prints al classIDs inside set
    void printClassIDs();
    //print specific details of a class by ID if found
    void printDetails(string classID);
    vector <Class> classes;
  };
}

#endif
