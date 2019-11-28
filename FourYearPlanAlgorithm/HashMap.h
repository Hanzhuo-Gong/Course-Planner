#ifndef HASHMAP_H
#define HASHMAP_H

#include "scuClass.h"
#include <math.h>

class HashMap {
public:
  HashMap();
  int hash(string cID);
  int getSize();
  bool containsClass(string cID);
  void insert(scuClass c);
  void printIDs();
  scuClass* getClass(string cID);
  vector <string> classIDs;
private:
  int size;
  scuClass classes[1000];
};

#endif
