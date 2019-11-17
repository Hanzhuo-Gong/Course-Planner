CREATE TABLE MajornEmphasis
(
  MajorName VARCHAR NOT NULL,
  RequiredGPA INT NOT NULL,
  RequiredCredits INT NOT NULL,
  MinEmpClasses INT NOT NULL,
  MinMajorClasses INT NOT NULL,
  PRIMARY KEY (MajorName)
);

CREATE TABLE Classes
(
  CourseName VARCHAR NOT NULL,
  CourseID INT,
  QuarterOffered VARCHAR NOT NULL,
  CreditGiven INT NOT NULL,
  CreditReq INT NOT NULL,
  HasPrereqs BOOLEAN NOT NULL,
  PRIMARY KEY (CourseName)
);

CREATE TABLE Prereqs
(
  PreReqName VARCHAR NOT NULL,
  CourseName VARCHAR NOT NULL,
  FOREIGN KEY (PreReqName) REFERENCES Classes(CourseName),
  FOREIGN KEY (CourseName) REFERENCES Classes(CourseName)
);

CREATE TABLE MajorReqs
(
  CourseName VARCHAR NOT NULL,
  MajorName VARCHAR NOT NULL,
  PRIMARY KEY (CourseName, MajorName),
  FOREIGN KEY (CourseName) REFERENCES Classes(CourseName),
  FOREIGN KEY (MajorName) REFERENCES MajornEmphasis(MajorName)
);

CREATE TABLE Student
(
  StudentID INT NOT NULL,
  Password INT,
  ClassDifficulty INT,
  MajorEmphasis VARCHAR NOT NULL,
  PRIMARY KEY (StudentID),
  FOREIGN KEY (MajorEmphasis) REFERENCES MajornEmphasis(MajorName)
);

CREATE TABLE FourYearPlan
(
  PlanID INT NOT NULL,
  GradDate DATE,
  CourseName VARCHAR NOT NULL,
  StudentID INT NOT NULL,
  PRIMARY KEY (PlanID),
  FOREIGN KEY (CourseName) REFERENCES Classes(CourseName),
  FOREIGN KEY (StudentID) REFERENCES Student(StudentID)
);

CREATE TABLE CoursesTaken
(
  CourseName VARCHAR NOT NULL,
  StudentID INT NOT NULL,
  PRIMARY KEY (CourseName, StudentID),
  FOREIGN KEY (CourseName) REFERENCES Classes(CourseName),
  FOREIGN KEY (StudentID) REFERENCES Student(StudentID)
);
