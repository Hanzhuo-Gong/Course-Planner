#include "Student.h"
#include <fstream>
#include <string>
#include <vector>

//add credit conditional (complete)
//NOTE:total credits from my dummy data is very CLOSE to 175
//so there is a possibility of a student completing ALL NECESSARY CLASSES but without enough credits to graduate
//maybe add a little bit more credits in the database to solve this, that's what I did to my dummy data

//write Student class that holds ID and previously taken scuClasses(complete)
//added a "year" variable to the Student class, no longer hard-coded 2019

//rewrite ID arrays to be included in each HashMap and be accessed in FourYearPlan, instead of hard-written in FourYearPlan (complete)

//change your jsonPrint() to whatever Junha wrote (complete)

//modified algorithm slightly to allow for better balance of classes, a student can be assigned up to 2 major/emphasis classes and 2 core classes a quarter (complete)

int main(int argc, char* argv[]) {
HashMap major; //insert these scuClasses into HashMaps of each category (ie: major requirements)
  HashMap core;
    HashMap softwareReqEmphasis; // going to be empty, only serves to exist to make the FourYearPlan p later on lol
    HashMap softwareTwoMoreEmphasis; //5 recommended emphasis classes here but only need to take two to fulfill requirement
  HashMap prevCompletedTest; // Previously completed classes

    ifstream fin;
        string filename = argv[1];
        fin.open(filename); //ADD NAME OF FILE HERE JUNHA
        int flagforhash = 0;
        int creditsAlreadyCompleted = 0;
        string line;
        while (!fin.eof())
         {
            getline(fin, line);
            int wordnum=0;
            string tempsmolword="";
            string tempclassID="", tempfullName="", tempsubject="",  tempquarters="", tempcreditsasstr="";
            int tempcredits;
            vector<string> prereqs;
            for ( int i= 0; i<line.length(); i++ )
            {
              if (line[i]==';')
                {
                  wordnum++;
                  switch (wordnum)
                    {
                      case 1:
                      tempclassID = tempsmolword;
                      break;
                      case 2:
                      tempfullName = tempsmolword;
                      break;
                      case 3:
                      tempsubject = tempsmolword;
                      break;
                      case 4:
                      tempquarters = tempsmolword;
                      break;
                      case 5:
                      tempcreditsasstr = tempsmolword;
                      //convert this string to int
                      tempcredits = stoi(tempcreditsasstr);
                      break;
                      case 6 ... 30:
                      prereqs.push_back(tempsmolword);
                      break;
                      default:
                      printf("error");
                  }
                  tempsmolword="";
                }
                else if (line=="!")
                  {
                    flagforhash++;
                  }
                else
                tempsmolword+=line[i];
              }
              scuClass temp(tempclassID, tempfullName, tempsubject,  tempquarters, tempcredits);
              for (int prereqIndex=0; prereqIndex<prereqs.size(); prereqIndex++)
              {
                temp.pushPreReq(prereqs[prereqIndex]);
              }
              switch (flagforhash)
                {
                  case 0:
                  major.insert(temp);
                  break;
                  case 1:
                  core.insert(temp);
                  break;
                  case 2:
                  softwareTwoMoreEmphasis.insert(temp);
                  break;
                  case 3:
                  prevCompletedTest.insert(temp);
                  creditsAlreadyCompleted += tempcredits;
                  break;
            }
        }
        fin.close();
  cout << "file analysis completed" << endl;

  FourYearPlan p(major, core, softwareReqEmphasis, softwareTwoMoreEmphasis, creditsAlreadyCompleted); //just construct the plan to be later used in Student, don't run any of its functions

/*
  HashMap prevCompletedTest; //HashMap of previously completed classes, insert scuClass of whatever student already completed
  prevCompletedTest.insert(CS10);
  prevCompletedTest.insert(MATH11);
  prevCompletedTest.insert(CTW1);
*/

  Student Neil("1411529", 2019, prevCompletedTest); //construct a Student with studentID, starting year, and HashMap of previouslyCompletedClasses
  Neil.buildPlan(p); //when building the plan use the previously declared FourYearPlan as an argument
}

