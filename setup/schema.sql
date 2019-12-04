USE PlanToGrad;

DROP TABLE IF EXISTS MajornEmphasis;
CREATE TABLE IF NOT EXISTS MajornEmphasis
(
  MajorName VARCHAR(255) NOT NULL,
  RequiredGPA INT NOT NULL,
  RequiredCredits INT NOT NULL,
  MinEmpClasses INT NOT NULL,
  MinMajorClasses INT NOT NULL,
  PRIMARY KEY (MajorName)
);

DROP TABLE IF EXISTS Classes;
CREATE TABLE IF NOT EXISTS Classes
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

DROP TABLE IF EXISTS Prereqs;
CREATE TABLE IF NOT EXISTS Prereqs
(
  PreReqName VARCHAR(255) NOT NULL,
  CourseID VARCHAR(255) NOT NULL,
  FOREIGN KEY (PreReqName) REFERENCES Classes(CourseID),
  FOREIGN KEY (CourseID) REFERENCES Classes(CourseID)
);

DROP TABLE IF EXISTS MajorReqs;
CREATE TABLE IF NOT EXISTS MajorReqs
(
  CourseID VARCHAR(255) NOT NULL,
  MajorName VARCHAR(255) NOT NULL,
  PRIMARY KEY (CourseID, MajorName),
  FOREIGN KEY (CourseID) REFERENCES Classes(CourseID),
  FOREIGN KEY (MajorName) REFERENCES MajornEmphasis(MajorName)
);

DROP TABLE IF EXISTS Student;
CREATE TABLE IF NOT EXISTS Student
(
  StudentID INT NOT NULL,
  Password INT,
  ClassDifficulty INT,
  QuartersCompleted INT NOT NULL,
  MaxQuarters INT NOT NULL,
  MaxUnits INT NOT NULL,
  MajorEmphasis VARCHAR(255) NOT NULL,
  PRIMARY KEY (StudentID),
  FOREIGN KEY (MajorEmphasis) REFERENCES MajornEmphasis(MajorName)
);

DROP TABLE IF EXISTS FourYearPlan;
CREATE TABLE IF NOT EXISTS FourYearPlan
(
  PlanID INT NOT NULL,
  GradDate DATE,
  CourseID VARCHAR(255) NOT NULL,
  StudentID INT NOT NULL,
  PRIMARY KEY (PlanID),
  FOREIGN KEY (CourseID) REFERENCES Classes(CourseID),
  FOREIGN KEY (StudentID) REFERENCES Student(StudentID)
);

DROP TABLE IF EXISTS CoursesTaken;
CREATE TABLE IF NOT EXISTS CoursesTaken
(
  CourseID VARCHAR(255) NOT NULL,
  StudentID INT NOT NULL,
  PRIMARY KEY (CourseID, StudentID),
  FOREIGN KEY (CourseID) REFERENCES Classes(CourseID),
  FOREIGN KEY (StudentID) REFERENCES Student(StudentID)
);
