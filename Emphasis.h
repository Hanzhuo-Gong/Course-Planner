#ifndef EMPHASIS_H
#define EMPHASIS_H

#include "Classes.h"

namespace Schedule {

  class Emphasis {
  public:
    //constructor that takes two sets, one of classes you're required to take for your emphasis, another of classes you only need to take two of for your emphasis, and also takes name of emphasis
    Emphasis(string e, Classes req, Classes two);
    //returns whether your required emphasis classes are complete and prints the incomplete ones if any
    bool requiredComplete();
    //returns whether or not you've taken at least two of the additional courses in your emphasis, prints how much more you may need if incomplete
    bool twoMoreComplete();
    //returns whether or not the required emphasis classes AND two additional emphasis classes are complete, uses two above functions
    bool complete();
    //marks a specific class as finished if found, checks if it's in required first then twoMore
    void markClassFinished(string classID);
    //prints all emphasis details
    void printEmphasisDetails();
    //prints details about a specific class by ID
    void printClassDetails(string classID);
  private:
    string emphasis;
    Classes required;
    Classes twoMore;
  };

}

#endif
