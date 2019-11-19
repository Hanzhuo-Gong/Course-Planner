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
  CourseID,
  QuarterOffered,
  CreditGiven,
  CreditReq,
  HasPrereqs
)
VALUES
(
  'Introduction to Computer Science',
  'CSCI 10 & L',
  '',
  5,
  0,
  false
),
(
  'Object-Oriented Programming',
  'CSCI 60 & L',
  '',
  5,
  0,
  true
),
(
  'Data Structures',
  'CSCI 61',
  '',
  4,
  0,
  true
),
(
  'Theory of Automata and Languages',
  'CSCI 161',
  '',
  5,
  0,
  true
),
(
  'Computational Complexity',
  'CSCI 162',
  '',
  5,
  0,
  true
),
-- Also COEN 179
(
  'Theory of Algorithms',
  'CSCI 163A',
  '',
  5,
  0,
  true
),
(
  'Advanced Theory of Algorithms',
  'CSCI 163B',
  '',
  5,
  0,
  true
),
(
  'Computer Simulation',
  'CSCI 164',
  '',
  5,
  0,
  true
),
(
  'Linear Programming',
  'CSCI 165',
  '',
  5,
  0,
  false
),
(
  'Numerical Analysis',
  'CSCI 166',
  '',
  5,
  0,
  true
),
(
  'Switching Theory and Boolean Algebra',
  'CSCI 167',
  '',
  5,
  0,
  false
),
(
  'Computer Graphics',
  'CSCI 168',
  '',
  5,
  0,
  true
),
(
  'Programming Languages',
  'CSCI 169',
  '',
  5,
  0,
  true
),
(
  'Applied Cryptography',
  'CSCI 181',
  '',
  5,
  0,
  true
),
(
  'Digital Steganography',
  'CSCI 182',
  '',
  5,
  0,
  true
),
(
  'Data Science',
  'CSCI 183',
  '',
  5,
  0,
  true
),
(
  'Applied Machine Learning',
  'CSCI 184',
  '',
  5,
  0,
  true
),
(
  'The Design and Management of Software',
  'CSCI 187',
  '',
  5,
  0,
  true
),
-- not sure if we need this lol
(
  'Advanced Topics',
  'CSCI 197',
  '',
  5,
  0,
  false
),
(
  'Introduction to Embedded Systems',
  'COEN 20 & L',
  '',
  5,
  0,
  true
),
(
  'Introduction to Logic Design',
  'COEN 21 & L',
  '',
  5,
  0,
  false
),
(
  'Real-Time Systems',
  'COEN 120 & L',
  '',
  5,
  0,
  true
),
(
  'Computer Architecture',
  'COEN 122 & L',
  '',
  5,
  0,
  true
),
(
  'Advanced Logic Design',
  'COEN 127 & L',
  '',
  5,
  0,
  true
),
(
  'Introduction to Parallel Programming',
  'COEN 145 & L',
  '',
  5,
  0,
  true
),
(
  'Computer Networks',
  'COEN 146 & L',
  '',
  5,
  0,
  true
),
(
  'Computer Graphics Systems',
  'COEN 148',
  '',
  4,
  0,
  true
),
(
  'Introduction to Information Security',
  'COEN 150',
  '',
  4,
  88,
  false
),
(
  'Introduction to Computer Forensics',
  'COEN 152 & L',
  '',
  5,
  0,
  true
),
(
  'Object-Oriented Analysis, Design, and Programming',
  'COEN 160 & L',
  '',
  5,
  0,
  true
),
(
  'Web Development',
  'COEN 161 & L',
  '',
  5,
  0,
  true
),
(
  'Web Infrastructure',
  'COEN 162',
  '',
  4,
  0,
  true
),
(
  'Web Usability',
  'COEN 163 & L',
  '',
  5,
  0,
  true
),
(
  'Advanced Web Development',
  'COEN 164 & L',
  '',
  5,
  0,
  true
),
(
  'Introduction to 3D Animation & Modeling/Modeling & Control Rigid Body Dynamics',
  'COEN 165',
  '',
  4,
  0,
  false
),
(
  'Artificial Intelligence',
  'COEN 166 & L',
  '',
  5,
  0,
  true
),
(
  'Mobile Application Development',
  'COEN 168 & L',
  '',
  5,
  0,
  true
),
(
  'Web Information Management',
  'COEN 169',
  '',
  4,
  0,
  true
),
(
  'Principles of Design and Implementation of Programming Languages',
  'COEN 171',
  '',
  4,
  0,
  true
),
(
  'Structure and Interpretation of Computer Programs',
  'COEN 172 & L',
  '',
  5,
  0,
  true
),
(
  'Logic Programming',
  'COEN 173 & L',
  '',
  5,
  0,
  true
),
(
  'Software Engineering Laboratory',
  'COEN 174 & L',
  '',
  5,
  0,
  true
),
(
  'Operating Systems',
  'COEN 177 & L',
  '',
  5,
  0,
  true
),
(
  'Introduction to Database Systems',
  'COEN 178 & L',
  '',
  5,
  0,
  true
),
(
  'Introduction to Information Storage',
  'COEN 180',
  '',
  4,
  0,
  true
),
(
  'Calculus and Analytic Geometry I',
  'MATH 11',
  '',
  4,
  0,
  false
),
(
  'Calculus and Analytic Geometry II',
  'MATH 12',
  '',
  4,
  0,
  true
),
(
  'Calculus and Analytic Geometry III',
  'MATH 13',
  '',
  4,
  0,
  true
),
(
  'Calculus and Analytic Geometry IV',
  'MATH 14',
  '',
  4,
  0,
  true
),
(
  'Discrete Mathematics',
  'MATH 51',
  '',
  4,
  0,
  false
),
(
  'Introduction to Abstract Algebra',
  'MATH 52',
  '',
  4,
  0,
  true
),
(
  'Linear Algebra',
  'MATH 53',
  '',
  4,
  0,
  true
),
(
  'A Survey of Geometry',
  'MATH 101',
  '',
  5,
  0,
  true
),
(
  'Probability and Statistics I',
  'MATH 122',
  '',
  5,
  0,
  true
),
(
  'Probability and Statistics II',
  'MATH 123',
  '',
  5,
  0,
  true
),
(
  'Theory of Numbers',
  'MATH 175',
  '',
  5,
  0,
  true
),
(
  'Combinatorics',
  'MATH 176',
  '',
  5,
  0,
  true
),
(
  'Graph Theory',
  'MATH 177',
  '',
  5,
  0,
  true
),
(
  'Cryptography',
  'MATH 178',
  '',
  5,
  0,
  false
)

INSERT INTO Prereqs
(
  PreReqName,
  CourseID
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
),
-- Algorithm Emphasis
(
  'CSCI 161',
  'CSCI 162'
),
(
  'CSCI 163A',
  'CSCI 163B'
),
(
  'MATH 51',
  'MATH 177'
)
-- Data Science Emphasis
(
  'CSCI 61',
  'CSCI 183'
),
(
  'MATH 53',
  'CSCI 183'
),
(
  'MATH 122',
  'CSCI 183'
),
(
  'CSCI 183',
  'CSCI 184'
),
(
  'MATH 53',
  'MATH 123'
),
(
  'MATH 122',
  'MATH 123'
),
-- Software Emphasis
(
  'CSCI 61',
  'CSCI 169'
),
(
  'MATH 51',
  'CSCI 169'
),
(
  'CSCI 61',
  'CSCI 187'
),
(
  'CSCI 61',
  'COEN 146'
),
-- Security Emphasis
(
  'COEN 20 & L',
  'CSCI 180'
),
(
  'MATH 178',
  'CSCI 181'
),
(
  'CSCI 10 & L',
  'CSCI 181'
),
-- Other Upper Division Classes
(
  'CSCI 10 & L',
  'CSCI 166'
),
(
  'MATH 53',
  'CSCI 166'
),
(
  'CSCI 10 & L',
  'CSCI 168'
),
(
  'MATH 13',
  'CSCI 168'
),
(
  'CSCI 61',
  'COEN 120 & L'
),
(
  'COEN 20 & L',
  'COEN 122 & L'
),
(
  'CSCI 21 & L',
  'COEN 122 & L'
),
(
  'COEN 21 & L',
  'COEN 127 & L'
),
(
  'CSCI 61',
  'COEN 145 & L'
),
(
  'CSCI 61',
  'COEN 148'
),
(
  'MATH 53',
  'COEN 148'
),
(
  'CSCI 61',
  'COEN 152 & L'
),
(
  'COEN 20 & L',
  'COEN 152 & L'
),
(
  'CSCI 61',
  'COEN 160 & L'
),
(
  'CSCI 61',
  'COEN 161 & L'
),
(
  'COEN 146 & L',
  'COEN 162'
),
(
  'CSCI 61',
  'COEN 163 & L'
),
(
  'COEN 161 & L',
  'COEN 164 & L'
),
(
  'CSCI 61',
  'COEN 166 & L'
),
(
  'MATH 51',
  'COEN 166 & L'
),
(
  'COEN 20 & L',
  'COEN 168 & L'
),
(
  'CSCI 61',
  'COEN 169'
),
(
  'MATH 122',
  'COEN 169'
),
(
  'CSCI 61',
  'COEN 171'
),
(
  'CSCI 61',
  'COEN 172 & L'
),
(
  'MATH 51',
  'COEN 172 & L'
),
(
  'CSCI 61',
  'COEN 173 & L'
),
(
  'MATH 51',
  'COEN 173 & L'
),
(
  'CSCI 61',
  'COEN 174 & L'
),
(
  'CSCI 61',
  'COEN 178 & L'
),
(
  'CSCI 61',
  'COEN 180'
),
(
  'MATH 13',
  'MATH 101'
),
(
  'MATH 52',
  'MATH 175'
),
(
  'MATH 51',
  'MATH 176'
),
(
  'MATH 51',
  'MATH 52'
)

INSERT INTO MajorReqs
(
  CourseID,
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
  'CSCI 162',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'CSCI 163B',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'MATH 177',
  'Computer Science, Algorithms and Complexity Emphasis'
),
--  two more courses from MATH 175, MATH 176, MATH 178, CSCI 165, CSCI 181, MATH 101 or any other additional upper division CSCI or COEN courses
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
  'CSCI 183',
  'Computer Science, Data Science Emphasis'
),
(
  'CSCI 184',
  'Computer Science, Data Science Emphasis'
),
(
  'MATH 123',
  'Computer Science, Data Science Emphasis'
),
-- two more courses from CSCI 164, CSCI 166 or any other upper division CSCI or COEN course
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
  'CSCI 169',
  'Computer Science, Software Emphasis'
),
(
  'CSCI 187',
  'Computer Science, Software Emphasis'
),
(
  'COEN 146 & L',
  'Computer Science, Software Emphasis'
),
-- one more course from CSCI 183, CSCI 168, CSCI 164, or any other upper division CSCI course. One more course from CSCI 183, 164, 168; COEN 163, 166, 168, or any other upper division CSCI or COEN course.
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
),
(
  'MATH 178',
  'Computer Science, Security Emphasis'
),
(
  'CSCI 180',
  'Computer Science, Security Emphasis'
),
(
  'CSCI 181',
  'Computer Science, Security Emphasis'
)
-- two more courses from MATH 175, COEN 152 & L, COEN 161 & L, COEN 146 & L or any other upper division CSCI or COEN course
