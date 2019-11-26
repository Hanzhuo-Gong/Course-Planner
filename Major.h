#ifndef MAJOR_H
#define MAJOR_H

#include "Classes.h"

namespace Schedule {

  class Major {

  public:
    //construct with pre-made set of classes and name of major
    Major(string majorName, Classes c);
    //returns whether every class is complete or not, prints out what's not complete if any
    bool complete();
    //marks a class state of completion as true based on ID if found
    void markClassFinished(string classID);
    //prints all details about major classes
    void printMajorDetails();
    //prints specific class details by ID
    void printClassDetails(string classID);
  private:
    string major;
    Classes m;
  };

}

#endif
