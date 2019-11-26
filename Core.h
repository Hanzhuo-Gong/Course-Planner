#ifndef CORE_H
#define CORE_H

#include "Classes.h"

namespace Schedule {

  class Core {
  public:
    //constructor takes in pre-made set of classes, will be the same for any student
    Core(Classes core);
    //returns whether ALL the classes are complete or not, prints incomplete ones if any
    bool complete();
    //changes state of specific class to true if found
    void markClassFinished(string classID);
    //print all core details
    void printCoreDetails();
    //print specific class details by ID
    void printClassDetails(string classID);
  private:
    Classes c;
  };

}

#endif
