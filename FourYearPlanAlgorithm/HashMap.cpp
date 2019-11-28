#include "HashMap.h"

HashMap::HashMap() {
  size = 0;
}

int HashMap::hash(string cID) {
  int exponent = 1;
  int hash = 0;
  for (int i = 0 ; i < cID.size() ; i++) {
    hash += cID[i] * pow(17,exponent);
    exponent++;
  }
  hash = hash%1000;
  //cout<<cID<<" Hash = "<<hash<<endl;
  if (hash < 0) {
    return hash * -1;
  }
  else {
    return hash;
  }
}

int HashMap::getSize() {
  return size;
}

bool HashMap::containsClass(string cID) {
  int h = hash(cID);
  while (classes[h].getID()!=cID) {
    h++;
    if (h>=1000) {
      h=0;
    }
    if (classes[h].getID()=="") {
      return false;
    }
  }
  return true;
}

void HashMap::insert(scuClass c) {
  int h = hash(c.getID());
  if (!containsClass(c.getID())) {
    while (classes[h].getID()!="") {
      h++;
      if (h>=999) {
        h=0;
      }
    }
    classes[h]=c;
    size++;
    //cout<<"inserted "<<c.getID()<<" in classes["<<h<<"]"<<endl;
    //cout<<size<<" classes stored"<<endl;
  }
  classIDs.push_back(c.getID());
}

void HashMap::printIDs() {
  if (!classIDs.empty()) {
    cout<<"classIDs in hash ordered by insertion: ";
    for (int i = 0 ; i < classIDs.size() ; i++) {
      cout<<classIDs[i]<<" ";
    }
    cout<<endl;
  }
}

scuClass* HashMap::getClass(string cID) {
  int h = hash(cID);
  while (classes[h].getID()!=cID) {
    h++;
    if (h>=1000) {
      h=0;
    }
    if (classes[h].getID()=="") {
      return NULL;
    }
  }
  return &classes[h];
}
