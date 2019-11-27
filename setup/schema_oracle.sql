DROP TABLE MajornEmphasis;
CREATE TABLE MajornEmphasis
(
  MajorName VARCHAR(255) NOT NULL,
  RequiredGPA INT NOT NULL,
  RequiredCredits INT NOT NULL,
  MinEmpClasses INT NOT NULL,
  MinMajorClasses INT NOT NULL,
  PRIMARY KEY (MajorName)
);

DROP TABLE Classes;
CREATE TABLE Classes
(
  CourseName VARCHAR(255) NOT NULL,
  CourseID VARCHAR(255) NOT NULL,
  QuarterOffered VARCHAR(255) NOT NULL,
  CreditGiven INT NOT NULL,
  CreditReq INT NOT NULL,
  HasPrereqs INT NOT NULL,
  Difficulty INT,
  PRIMARY KEY (CourseID)
);

DROP TABLE Prereqs;
CREATE TABLE Prereqs
(
  PreReqName VARCHAR(255) NOT NULL,
  CourseID VARCHAR(255) NOT NULL,
  FOREIGN KEY (PreReqName) REFERENCES Classes(CourseID),
  FOREIGN KEY (CourseID) REFERENCES Classes(CourseID)
);

DROP TABLE MajorReqs;
CREATE TABLE MajorReqs
(
  CourseID VARCHAR(255) NOT NULL,
  MajorName VARCHAR(255) NOT NULL,
  PRIMARY KEY (CourseID, MajorName),
  FOREIGN KEY (CourseID) REFERENCES Classes(CourseID),
  FOREIGN KEY (MajorName) REFERENCES MajornEmphasis(MajorName)
);

DROP TABLE Student;
CREATE TABLE Student
(
  StudentID INT NOT NULL,
  Password INT,
  ClassDifficulty INT,
  NumberOfQuartersTaken INT,
  TotalQuarters INT,
  MaxUnitsPerQuarter INT,
  MajorEmphasis VARCHAR(255) NOT NULL,
  PRIMARY KEY (StudentID),
  FOREIGN KEY (MajorEmphasis) REFERENCES MajornEmphasis(MajorName)
);

DROP TABLE FourYearPlan;
CREATE TABLE FourYearPlan
(
  PlanID INT NOT NULL,
  GradDate DATE,
  CourseID VARCHAR(255) NOT NULL,
  StudentID INT NOT NULL,
  PRIMARY KEY (PlanID),
  FOREIGN KEY (CourseID) REFERENCES Classes(CourseID),
  FOREIGN KEY (StudentID) REFERENCES Student(StudentID)
);

DROP TABLE CoursesTaken;
CREATE TABLE CoursesTaken
(
  CourseID VARCHAR(255) NOT NULL,
  StudentID INT NOT NULL,
  PRIMARY KEY (CourseID, StudentID),
  FOREIGN KEY (CourseID) REFERENCES Classes(CourseID),
  FOREIGN KEY (StudentID) REFERENCES Student(StudentID)
);
