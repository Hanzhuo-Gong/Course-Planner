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
  CourseID VARCHAR NOT NULL,
  QuarterOffered VARCHAR NOT NULL,
  CreditGiven INT NOT NULL,
  CreditReq INT NOT NULL,
  HasPrereqs BOOLEAN NOT NULL,
  PRIMARY KEY (CourseID)
);

CREATE TABLE Prereqs
(
  PreReqName VARCHAR NOT NULL,
  CourseID VARCHAR NOT NULL,
  FOREIGN KEY (PreReqName) REFERENCES Classes(CourseID),
  FOREIGN KEY (CourseID) REFERENCES Classes(CourseID)
);

CREATE TABLE MajorReqs
(
  CourseID VARCHAR NOT NULL,
  MajorName VARCHAR NOT NULL,
  PRIMARY KEY (CourseID, MajorName),
  FOREIGN KEY (CourseID) REFERENCES Classes(CourseID),
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
  CourseID VARCHAR NOT NULL,
  StudentID INT NOT NULL,
  PRIMARY KEY (PlanID),
  FOREIGN KEY (CourseID) REFERENCES Classes(CourseID),
  FOREIGN KEY (StudentID) REFERENCES Student(StudentID)
);

CREATE TABLE CoursesTaken
(
  CourseID VARCHAR NOT NULL,
  StudentID INT NOT NULL,
  PRIMARY KEY (CourseID, StudentID),
  FOREIGN KEY (CourseID) REFERENCES Classes(CourseID),
  FOREIGN KEY (StudentID) REFERENCES Student(StudentID)
);
