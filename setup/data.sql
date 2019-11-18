INSERT INTO MajornEmphasis
(
  MajorName,
  RequiredGPA,
  RequiredCredits,
  MinEmpClasses,
  MinMajorClasses
)
VALUES
(
  'Computer Science, Algorithms and Complexity Emphasis',
  2,
  175,
  5,
  20
),
(
  'Computer Science, Data Science Emphasis', 
  2,
  175,
  5,
  20
),
(
  'Computer Science, Software Emphasis',
  2,
  175,
  5,
  20
),
(
  'Computer Science, Security Emphasis',
  2,
  175,
  5,
  20
)

INSERT INTO Classes
(
  CourseName,
  QuarterOffered,
  CreditGiven,
  CreditReq,
  HasPrereqs
)
VALUES
(
  'CSCI 10 & L',
  '',
  5,
  0,
  false
),
(
  'CSCI 60 & L',
  '',
  5,
  0,
  true
),
(
  'CSCI 61',
  '',
  4,
  0,
  true
),
(
  'CSCI 161',
  '',
  5,
  0,
  true
),
(
  'CSCI 163A',
  '',
  5,
  0,
  true
),
(
  'COEN 20 & L',
  '',
  5,
  0,
  true
),
(
  'COEN 21 & L',
  '',
  5,
  0,
  false
),
(
  'COEN 177 & L',
  '',
  5,
  0,
  true
),
(
  'MATH 11',
  '',
  4,
  0,
  false
),
(
  'MATH 12',
  '',
  4,
  0,
  true
),
(
  'MATH 13',
  '',
  4,
  0,
  true
),
(
  'MATH 14',
  '',
  4,
  0,
  true
),
(
  'MATH 51',
  '',
  4,
  0,
  false
),
(
  'MATH 53',
  '',
  4,
  0,
  true
),
(
  'MATH 122',
  '',
  5,
  0,
  true
)

INSERT INTO Prereqs
(
  PreReqName,
  CourseName
)
VALUES
(
  'CSCI 10 & L',
  'CSCI 60 & L'
),
(
  'CSCI 60 & L',
  'CSCI 61'
),
(
  'MATH 11',
  'MATH 12'
),
(
  'MATH 12',
  'MATH 13'
),
(
  'MATH 13',
  'MATH 14'
),
(
  'CSCI 60 & L',
  'COEN 20 & L'
),
(
  'MATH 13',
  'MATH 53'
),
(
  'MATH 51',
  'CSCI 161'
),
(
  'CSCI 61',
  'CSCI 163A'
),
(
  'MATH 51',
  'CSCI 163A'
),
(
  'MATH 14',
  'MATH 122'
),
(
  'COEN 20',
  'COEN 177 & L'
),
(
  'CSCI 61',
  'COEN 177 & L'
)

INSERT INTO MajorReqs
(
  CourseName,
  MajorName
)
VALUES
(
  'CSCI 10 & L',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'CSCI 60 & L',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'CSCI 61',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'MATH 11',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'MATH 12',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'MATH 13',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'MATH 14',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'COEN 20 & L',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'COEN 21 & L',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'MATH 51',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'MATH 53',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'CSCI 161',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'CSCI 163A',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'MATH 122',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'COEN 177 & L',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'CSCI 10 & L',
  'Computer Science, Data Science Emphasis'
),
(
  'CSCI 60 & L',
  'Computer Science, Data Science Emphasis'
),
(
  'CSCI 61',
  'Computer Science, Data Science Emphasis'
),
(
  'MATH 11',
  'Computer Science, Data Science Emphasis'
),
(
  'MATH 12',
  'Computer Science, Data Science Emphasis'
),
(
  'MATH 13',
  'Computer Science, Data Science Emphasis'
),
(
  'MATH 14',
  'Computer Science, Data Science Emphasis'
),
(
  'COEN 20 & L',
  'Computer Science, Data Science Emphasis'
),
(
  'COEN 21 & L',
  'Computer Science, Data Science Emphasis'
),
(
  'MATH 51',
  'Computer Science, Data Science Emphasis'
),
(
  'MATH 53',
  'Computer Science, Data Science Emphasis'
),
(
  'CSCI 161',
  'Computer Science, Data Science Emphasis'
),
(
  'CSCI 163A',
  'Computer Science, Data Science Emphasis'
),
(
  'MATH 122',
  'Computer Science, Data Science Emphasis'
),
(
  'COEN 177 & L',
  'Computer Science, Data Science Emphasis'
),
(
  'CSCI 10 & L',
  'Computer Science, Software Emphasis'
),
(
  'CSCI 60 & L',
  'Computer Science, Software Emphasis'
),
(
  'CSCI 61',
  'Computer Science, Software Emphasis'
),
(
  'MATH 11',
  'Computer Science, Software Emphasis'
),
(
  'MATH 12',
  'Computer Science, Software Emphasis'
),
(
  'MATH 13',
  'Computer Science, Software Emphasis'
),
(
  'MATH 14',
  'Computer Science, Software Emphasis'
),
(
  'COEN 20 & L',
  'Computer Science, Software Emphasis'
),
(
  'COEN 21 & L',
  'Computer Science, Software Emphasis'
),
(
  'MATH 51',
  'Computer Science, Software Emphasis'
),
(
  'MATH 53',
  'Computer Science, Software Emphasis'
),
(
  'CSCI 161',
  'Computer Science, Software Emphasis'
),
(
  'CSCI 163A',
  'Computer Science, Software Emphasis'
),
(
  'MATH 122',
  'Computer Science, Software Emphasis'
),
(
  'COEN 177 & L',
  'Computer Science, Software Emphasis'
),
(
  'CSCI 10 & L',
  'Computer Science, Security Emphasis'
),
(
  'CSCI 60 & L',
  'Computer Science, Security Emphasis'
),
(
  'CSCI 61',
  'Computer Science, Security Emphasis'
),
(
  'MATH 11',
  'Computer Science, Security Emphasis'
),
(
  'MATH 12',
  'Computer Science, Security Emphasis'
),
(
  'MATH 13',
  'Computer Science, Security Emphasis'
),
(
  'MATH 14',
  'Computer Science, Security Emphasis'
),
(
  'COEN 20 & L',
  'Computer Science, Security Emphasis'
),
(
  'COEN 21 & L',
  'Computer Science, Security Emphasis'
),
(
  'MATH 51',
  'Computer Science, Security Emphasis'
),
(
  'MATH 53',
  'Computer Science, Security Emphasis'
),
(
  'CSCI 161',
  'Computer Science, Security Emphasis'
),
(
  'CSCI 163A',
  'Computer Science, Security Emphasis'
),
(
  'MATH 122',
  'Computer Science, Security Emphasis'
),
(
  'COEN 177 & L',
  'Computer Science, Security Emphasis'
)
