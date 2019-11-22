DELETE FROM MajornEmphasis;
INSERT INTO MajornEmphasis
(
  MajorName,
  RequiredGPA,
  RequiredCredits,
  MinEmpClasses,
  MinMajorClasses
)
SELECT
  'Computer Science, Algorithms and Complexity Emphasis',
  2,
  175,
  5,
  20
FROM dual UNION ALL
SELECT
  'Computer Science, Data Science Emphasis', 
  2,
  175,
  5,
  20
FROM dual UNION ALL
SELECT
  'Computer Science, Software Emphasis',
  2,
  175,
  5,
  20
FROM dual UNION ALL
SELECT
  'Computer Science, Security Emphasis',
  2,
  175,
  5,
  20
FROM dual;

DELETE FROM Classes;
INSERT INTO Classes
(
  CourseName,
  CourseID,
  QuarterOffered,
  CreditGiven,
  CreditReq,
  HasPrereqs
)
SELECT
  'Introduction to Computer Science',
  'CSCI 10 and L',
  'FWS',
  5,
  0,
  0
FROM dual UNION ALL
SELECT
  'Object-Oriented Programming',
  'CSCI 60 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Data Structures',
  'CSCI 61',
  'FWS',
  4,
  0,
  1
FROM dual UNION ALL
SELECT
  'Theory of Automata and Languages',
  'CSCI 161',
  'FW',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Computational Complexity',
  'CSCI 162',
  'WE',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Theory of Algorithms',
  'CSCI 163A',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Advanced Theory of Algorithms',
  'CSCI 163B',
  'W',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Computer Simulation',
  'CSCI 164',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Linear Programming',
  'CSCI 165',
  'WO',
  5,
  0,
  0
FROM dual UNION ALL
SELECT
  'Numerical Analysis',
  'CSCI 166',
  'W',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Switching Theory and Boolean Algebra',
  'CSCI 167',
  'FWS',
  5,
  0,
  0
FROM dual UNION ALL
SELECT
  'Computer Graphics',
  'CSCI 168',
  'F',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Programming Languages',
  'CSCI 169',
  'S',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Applied Cryptography',
  'CSCI 181',
  'SO',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Digital Steganography',
  'CSCI 182',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Data Science',
  'CSCI 183',
  'WS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Applied Machine Learning',
  'CSCI 184',
  'S',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'The Design and Management of Software',
  'CSCI 187',
  'F',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Advanced Topics',
  'CSCI 197',
  'FWS',
  5,
  0,
  0
FROM dual UNION ALL
SELECT
  'Introduction to Embedded Systems',
  'COEN 20 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Introduction to Logic Design',
  'COEN 21 and L',
  'FWS',
  5,
  0,
  0
FROM dual UNION ALL
SELECT
  'Real-Time Systems',
  'COEN 120 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Computer Architecture',
  'COEN 122 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Advanced Logic Design',
  'COEN 127 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Introduction to Parallel Programming',
  'COEN 145 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Computer Networks',
  'COEN 146 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Computer Graphics Systems',
  'COEN 148',
  'FWS',
  4,
  0,
  1
FROM dual UNION ALL
SELECT
  'Introduction to Information Security',
  'COEN 150',
  'FWS',
  4,
  88,
  0
FROM dual UNION ALL
SELECT
  'Introduction to Computer Forensics',
  'COEN 152 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Object-Oriented Analysis, Design, and Programming',
  'COEN 160 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Web Development',
  'COEN 161 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Web Infrastructure',
  'COEN 162',
  'FWS',
  4,
  0,
  1
FROM dual UNION ALL
SELECT
  'Web Usability',
  'COEN 163 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Advanced Web Development',
  'COEN 164 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Introduction to 3D Animation and Modeling/Modeling and Control Rigid Body Dynamics',
  'COEN 165',
  'FWS',
  4,
  0,
  0
FROM dual UNION ALL
SELECT
  'Artificial Intelligence',
  'COEN 166 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Mobile Application Development',
  'COEN 168 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Web Information Management',
  'COEN 169',
  'FWS',
  4,
  0,
  1
FROM dual UNION ALL
SELECT
  'Principles of Design and Implementation of Programming Languages',
  'COEN 171',
  'FWS',
  4,
  0,
  1
FROM dual UNION ALL
SELECT
  'Structure and Interpretation of Computer Programs',
  'COEN 172 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Logic Programming',
  'COEN 173 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Software Engineering Laboratory',
  'COEN 174 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Operating Systems',
  'COEN 177 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Introduction to Database Systems',
  'COEN 178 and L',
  'FWS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Introduction to Information Storage',
  'COEN 180',
  'FWS',
  4,
  0,
  1
FROM dual UNION ALL
SELECT
  'Calculus and Analytic Geometry I',
  'MATH 11',
  'FWS',
  4,
  0,
  0
FROM dual UNION ALL
SELECT
  'Calculus and Analytic Geometry II',
  'MATH 12',
  'FWS',
  4,
  0,
  1
FROM dual UNION ALL
SELECT
  'Calculus and Analytic Geometry III',
  'MATH 13',
  'FWS',
  4,
  0,
  1
FROM dual UNION ALL
SELECT
  'Calculus and Analytic Geometry IV',
  'MATH 14',
  'FWS',
  4,
  0,
  1
FROM dual UNION ALL
SELECT
  'Discrete Mathematics',
  'MATH 51',
  'FWS',
  4,
  0,
  0
FROM dual UNION ALL
SELECT
  'Introduction to Abstract Algebra',
  'MATH 52',
  'FWS',
  4,
  0,
  1
FROM dual UNION ALL
SELECT
  'Linear Algebra',
  'MATH 53',
  'FWS',
  4,
  0,
  1
FROM dual UNION ALL
SELECT
  'A Survey of Geometry',
  'MATH 101',
  'WO',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Probability and Statistics I',
  'MATH 122',
  'FW',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Probability and Statistics II',
  'MATH 123',
  'WS',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Theory of Numbers',
  'MATH 175',
  'SO',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Combinatorics',
  'MATH 176',
  'S',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Graph Theory',
  'MATH 177',
  'WE',
  5,
  0,
  1
FROM dual UNION ALL
SELECT
  'Cryptography',
  'MATH 178',
  'W',
  5,
  0,
  0
FROM dual;

DELETE FROM Prereqs;
INSERT INTO Prereqs
(
  PreReqName,
  CourseID
)
SELECT
  'CSCI 10 and L',
  'CSCI 60 and L'
FROM dual UNION ALL
SELECT
  'CSCI 60 and L',
  'CSCI 61'
FROM dual UNION ALL
SELECT
  'MATH 11',
  'MATH 12'
FROM dual UNION ALL
SELECT
  'MATH 12',
  'MATH 13'
FROM dual UNION ALL
SELECT
  'MATH 13',
  'MATH 14'
FROM dual UNION ALL
SELECT
  'CSCI 60 and L',
  'COEN 20 and L'
FROM dual UNION ALL
SELECT
  'MATH 13',
  'MATH 53'
FROM dual UNION ALL
SELECT
  'MATH 51',
  'CSCI 161'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'CSCI 163A'
FROM dual UNION ALL
SELECT
  'MATH 51',
  'CSCI 163A'
FROM dual UNION ALL
SELECT
  'MATH 14',
  'MATH 122'
FROM dual UNION ALL
SELECT
  'COEN 20 and L',
  'COEN 177 and L'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 177 and L'
FROM dual UNION ALL
SELECT
  'CSCI 161',
  'CSCI 162'
FROM dual UNION ALL
SELECT
  'CSCI 163A',
  'CSCI 163B'
FROM dual UNION ALL
SELECT
  'MATH 51',
  'MATH 177'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'CSCI 183'
FROM dual UNION ALL
SELECT
  'MATH 53',
  'CSCI 183'
FROM dual UNION ALL
SELECT
  'MATH 122',
  'CSCI 183'
FROM dual UNION ALL
SELECT
  'CSCI 183',
  'CSCI 184'
FROM dual UNION ALL
SELECT
  'MATH 53',
  'MATH 123'
FROM dual UNION ALL
SELECT
  'MATH 122',
  'MATH 123'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'CSCI 169'
FROM dual UNION ALL
SELECT
  'MATH 51',
  'CSCI 169'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'CSCI 187'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 146 and L'
FROM dual UNION ALL
SELECT
  'COEN 20 and L',
  'CSCI 180'
FROM dual UNION ALL
SELECT
  'MATH 178',
  'CSCI 181'
FROM dual UNION ALL
SELECT
  'CSCI 10 and L',
  'CSCI 181'
FROM dual UNION ALL
SELECT
  'CSCI 10 and L',
  'CSCI 166'
FROM dual UNION ALL
SELECT
  'MATH 53',
  'CSCI 166'
FROM dual UNION ALL
SELECT
  'CSCI 10 and L',
  'CSCI 168'
FROM dual UNION ALL
SELECT
  'MATH 13',
  'CSCI 168'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 120 and L'
FROM dual UNION ALL
SELECT
  'COEN 20 and L',
  'COEN 122 and L'
FROM dual UNION ALL
SELECT
  'COEN 21 and L',
  'COEN 122 and L'
FROM dual UNION ALL
SELECT
  'COEN 21 and L',
  'COEN 127 and L'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 145 and L'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 148'
FROM dual UNION ALL
SELECT
  'MATH 53',
  'COEN 148'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 152 and L'
FROM dual UNION ALL
SELECT
  'COEN 20 and L',
  'COEN 152 and L'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 160 and L'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 161 and L'
FROM dual UNION ALL
SELECT
  'COEN 146 and L',
  'COEN 162'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 163 and L'
FROM dual UNION ALL
SELECT
  'COEN 161 and L',
  'COEN 164 and L'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 166 and L'
FROM dual UNION ALL
SELECT
  'MATH 51',
  'COEN 166 and L'
FROM dual UNION ALL
SELECT
  'COEN 20 and L',
  'COEN 168 and L'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 169'
FROM dual UNION ALL
SELECT
  'MATH 122',
  'COEN 169'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 171'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 172 and L'
FROM dual UNION ALL
SELECT
  'MATH 51',
  'COEN 172 and L'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 173 and L'
FROM dual UNION ALL
SELECT
  'MATH 51',
  'COEN 173 and L'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 174 and L'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 178 and L'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'COEN 180'
FROM dual UNION ALL
SELECT
  'MATH 13',
  'MATH 101'
FROM dual UNION ALL
SELECT
  'MATH 52',
  'MATH 175'
FROM dual UNION ALL
SELECT
  'MATH 51',
  'MATH 176'
FROM dual UNION ALL
SELECT
  'MATH 51',
  'MATH 52'
FROM dual;

DELETE FROM MajorReqs;
INSERT INTO MajorReqs
(
  CourseID,
  MajorName
)
SELECT
  'CSCI 10 and L',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 60 and L',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 11',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 12',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 13',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 14',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'COEN 20 and L',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'COEN 21 and L',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 51',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 53',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 161',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 163A',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 122',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'COEN 177 and L',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 162',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 163B',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 177',
  'Computer Science, Algorithms and Complexity Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 10 and L',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 60 and L',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 11',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 12',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 13',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 14',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'COEN 20 and L',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'COEN 21 and L',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 51',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 53',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 161',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 163A',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 122',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'COEN 177 and L',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 183',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 184',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 123',
  'Computer Science, Data Science Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 10 and L',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 60 and L',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 11',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 12',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 13',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 14',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'COEN 20 and L',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'COEN 21 and L',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 51',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 53',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 161',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 163A',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 122',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'COEN 177 and L',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 169',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 187',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'COEN 146 and L',
  'Computer Science, Software Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 10 and L',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 60 and L',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 61',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 11',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 12',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 13',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 14',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'COEN 20 and L',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'COEN 21 and L',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 51',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 53',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 161',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 163A',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 122',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'COEN 177 and L',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'MATH 178',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 180',
  'Computer Science, Security Emphasis'
FROM dual UNION ALL
SELECT
  'CSCI 181',
  'Computer Science, Security Emphasis'
FROM dual;
