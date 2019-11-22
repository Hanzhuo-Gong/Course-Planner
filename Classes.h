#ifndef CLASSES_H
#define CLASSES_H

#include "Class.h"

namespace Schedule {
  class Classes {
  public:
    int getClassIndex(string classID);
    bool getClassState(string classID);
    bool getClassFeasible(string classID);
    bool getClassAvailable(string classID, string quarter, int year);
    void printPreReqs(string classID);
    void insert(Class c);
    void printClassIDs();
    void printDetails(string classID);
  private:
    vector <Class> classes;
  };
}

#endif
