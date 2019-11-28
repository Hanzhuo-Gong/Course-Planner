USE PlanToGrad;

DELETE FROM MajornEmphasis;
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
),
(
  'Core',
  0,
  0,
  0,
  0
);

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
VALUES
(
  'Introduction to Computer Science',
  'CSCI 10 and L',
  'FWS',
  5,
  0,
  0
),
(
  'Object-Oriented Programming',
  'CSCI 60 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Data Structures',
  'CSCI 61',
  'FWS',
  4,
  0,
  1
),
(
  'Theory of Automata and Languages',
  'CSCI 161',
  'FW',
  5,
  0,
  1
),
(
  'Computational Complexity',
  'CSCI 162',
  'WE',
  5,
  0,
  1
),
(
  'Theory of Algorithms',
  'CSCI 163A',
  'FWS',
  5,
  0,
  1
),
(
  'Advanced Theory of Algorithms',
  'CSCI 163B',
  'W',
  5,
  0,
  1
),
(
  'Computer Simulation',
  'CSCI 164',
  'FWS',
  5,
  0,
  1
),
(
  'Linear Programming',
  'CSCI 165',
  'WO',
  5,
  0,
  0
),
(
  'Numerical Analysis',
  'CSCI 166',
  'W',
  5,
  0,
  1
),
(
  'Switching Theory and Boolean Algebra',
  'CSCI 167',
  'FWS',
  5,
  0,
  0
),
(
  'Computer Graphics',
  'CSCI 168',
  'F',
  5,
  0,
  1
),
(
  'Programming Languages',
  'CSCI 169',
  'S',
  5,
  0,
  1
),
(
  'Computer Security',
  'CSCI 180',
  'F',
  5,
  0,
  1
),
(
  'Applied Cryptography',
  'CSCI 181',
  'SO',
  5,
  0,
  1
),
(
  'Digital Steganography',
  'CSCI 182',
  'FWS',
  5,
  0,
  1
),
(
  'Data Science',
  'CSCI 183',
  'WS',
  5,
  0,
  1
),
(
  'Applied Machine Learning',
  'CSCI 184',
  'S',
  5,
  0,
  1
),
(
  'The Design and Management of Software',
  'CSCI 187',
  'F',
  5,
  0,
  1
),
(
  'Advanced Topics',
  'CSCI 197',
  'FWS',
  5,
  0,
  0
),
(
  'Introduction to Embedded Systems',
  'COEN 20 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Introduction to Logic Design',
  'COEN 21 and L',
  'FWS',
  5,
  0,
  0
),
(
  'Real-Time Systems',
  'COEN 120 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Computer Architecture',
  'COEN 122 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Advanced Logic Design',
  'COEN 127 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Introduction to Parallel Programming',
  'COEN 145 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Computer Networks',
  'COEN 146 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Computer Graphics Systems',
  'COEN 148',
  'FWS',
  4,
  0,
  1
),
(
  'Introduction to Information Security',
  'COEN 150',
  'FWS',
  4,
  88,
  0
),
(
  'Introduction to Computer Forensics',
  'COEN 152 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Object-Oriented Analysis, Design, and Programming',
  'COEN 160 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Web Development',
  'COEN 161 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Web Infrastructure',
  'COEN 162',
  'FWS',
  4,
  0,
  1
),
(
  'Web Usability',
  'COEN 163 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Advanced Web Development',
  'COEN 164 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Introduction to 3D Animation and Modeling/Modeling and Control Rigid Body Dynamics',
  'COEN 165',
  'FWS',
  4,
  0,
  0
),
(
  'Artificial Intelligence',
  'COEN 166 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Mobile Application Development',
  'COEN 168 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Web Information Management',
  'COEN 169',
  'FWS',
  4,
  0,
  1
),
(
  'Principles of Design and Implementation of Programming Languages',
  'COEN 171',
  'FWS',
  4,
  0,
  1
),
(
  'Structure and Interpretation of Computer Programs',
  'COEN 172 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Logic Programming',
  'COEN 173 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Software Engineering Laboratory',
  'COEN 174 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Operating Systems',
  'COEN 177 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Introduction to Database Systems',
  'COEN 178 and L',
  'FWS',
  5,
  0,
  1
),
(
  'Introduction to Information Storage',
  'COEN 180',
  'FWS',
  4,
  0,
  1
),
(
  'Calculus and Analytic Geometry I',
  'MATH 11',
  'FWS',
  4,
  0,
  0
),
(
  'Calculus and Analytic Geometry II',
  'MATH 12',
  'FWS',
  4,
  0,
  1
),
(
  'Calculus and Analytic Geometry III',
  'MATH 13',
  'FWS',
  4,
  0,
  1
),
(
  'Calculus and Analytic Geometry IV',
  'MATH 14',
  'FWS',
  4,
  0,
  1
),
(
  'Discrete Mathematics',
  'MATH 51',
  'FWS',
  4,
  0,
  0
),
(
  'Introduction to Abstract Algebra',
  'MATH 52',
  'FWS',
  4,
  0,
  1
),
(
  'Linear Algebra',
  'MATH 53',
  'FWS',
  4,
  0,
  1
),
(
  'A Survey of Geometry',
  'MATH 101',
  'WO',
  5,
  0,
  1
),
(
  'Probability and Statistics I',
  'MATH 122',
  'FW',
  5,
  0,
  1
),
(
  'Probability and Statistics II',
  'MATH 123',
  'WS',
  5,
  0,
  1
),
(
  'Theory of Numbers',
  'MATH 175',
  'SO',
  5,
  0,
  1
),
(
  'Combinatorics',
  'MATH 176',
  'S',
  5,
  0,
  1
),
(
  'Graph Theory',
  'MATH 177',
  'WE',
  5,
  0,
  1
),
(
  'Cryptography',
  'MATH 178',
  'W',
  5,
  0,
  0
),
(
  'CTW 1',
  'CTW 1',
  'FWS',
  4,
  0,
  0
),
(
  'CTW 2',
  'CTW 2',
  'FWS',
  4,
  0,
  1
),
(
  'Advanced Writing',
  'Advanced Writing',
  'FWS',
  5,
  0,
  1
),
(
  'Ethics',
  'Ethics',
  'FWS',
  4,
  0,
  0
),
(
  'Diversity',
  'Diversity',
  'FWS',
  4,
  0,
  0
),
(
  'Arts',
  'Arts',
  'FWS',
  4,
  0,
  0
),
(
  'Language 1',
  'Language 1',
  'FWS',
  4,
  0,
  0
),
(
  'Language 2',
  'Language 2',
  'FWS',
  4,
  0,
  1
),
(
  'Natural Science',
  'Natural Science',
  'FWS',
  4,
  0,
  0
),
(
  'RTC 1',
  'RTC 1',
  'FWS',
  4,
  0,
  0
),
(
  'RTC 2',
  'RTC 2',
  'FWS',
  4,
  0,
  1
),
(
  'RTC 3',
  'RTC 3',
  'FWS',
  5,
  88,
  1
),
(
  'Social Science',
  'Social Science',
  'FWS',
  4,
  0,
  0
),
(
  'Culture and Ideas 1',
  'Culture and Ideas 1',
  'FWS',
  4,
  0,
  0
),
(
  'Culture and Ideas 2',
  'Culture and Ideas 2',
  'FWS',
  4,
  0,
  1
),
(
  'Culture and Ideas 3',
  'Culture and Ideas 3',
  'FWS',
  4,
  0,
  1
),
(
  'Civic Engagement',
  'Civic Engagement',
  'FWS',
  4,
  0,
  0
),
(
  'Experiential Learning and Social Justice',
  'ELSJ',
  'FWS',
  4,
  0,
  0
);

DELETE FROM Prereqs;
INSERT INTO Prereqs
(
  PreReqName,
  CourseID
)
VALUES
(
  'CSCI 10 and L',
  'CSCI 60 and L'
),
(
  'CSCI 60 and L',
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
  'CSCI 60 and L',
  'COEN 20 and L'
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
  'COEN 20 and L',
  'COEN 177 and L'
),
(
  'CSCI 61',
  'COEN 177 and L'
),
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
),
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
  'COEN 146 and L'
),
(
  'COEN 20 and L',
  'CSCI 180'
),
(
  'MATH 178',
  'CSCI 181'
),
(
  'CSCI 10 and L',
  'CSCI 181'
),
(
  'CSCI 10 and L',
  'CSCI 166'
),
(
  'MATH 53',
  'CSCI 166'
),
(
  'CSCI 10 and L',
  'CSCI 168'
),
(
  'MATH 13',
  'CSCI 168'
),
(
  'CSCI 61',
  'COEN 120 and L'
),
(
  'COEN 20 and L',
  'COEN 122 and L'
),
(
  'COEN 21 and L',
  'COEN 122 and L'
),
(
  'COEN 21 and L',
  'COEN 127 and L'
),
(
  'CSCI 61',
  'COEN 145 and L'
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
  'COEN 152 and L'
),
(
  'COEN 20 and L',
  'COEN 152 and L'
),
(
  'CSCI 61',
  'COEN 160 and L'
),
(
  'CSCI 61',
  'COEN 161 and L'
),
(
  'COEN 146 and L',
  'COEN 162'
),
(
  'CSCI 61',
  'COEN 163 and L'
),
(
  'COEN 161 and L',
  'COEN 164 and L'
),
(
  'CSCI 61',
  'COEN 166 and L'
),
(
  'MATH 51',
  'COEN 166 and L'
),
(
  'COEN 20 and L',
  'COEN 168 and L'
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
  'COEN 172 and L'
),
(
  'MATH 51',
  'COEN 172 and L'
),
(
  'CSCI 61',
  'COEN 173 and L'
),
(
  'MATH 51',
  'COEN 173 and L'
),
(
  'CSCI 61',
  'COEN 174 and L'
),
(
  'CSCI 61',
  'COEN 178 and L'
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
),
(
  'Language 1',
  'Language 2'
),
(
  'RTC 1',
  'RTC 2'
),
(
  'RTC 2',
  'RTC 3'
),
(
  'Culture and Ideas 1',
  'Culture and Ideas 2'
),
(
  'Culture and Ideas 2',
  'Culture and Ideas 3'
),
(
  'CTW 1',
  'CTW 2'
),
(
  'CTW 2',
  'Advanced Writing'
);

DELETE FROM MajorReqs;
INSERT INTO MajorReqs
(
  CourseID,
  MajorName
)
VALUES
(
  'CSCI 10 and L',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'CSCI 60 and L',
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
  'COEN 20 and L',
  'Computer Science, Algorithms and Complexity Emphasis'
),
(
  'COEN 21 and L',
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
  'COEN 177 and L',
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
(
  'CSCI 10 and L',
  'Computer Science, Data Science Emphasis'
),
(
  'CSCI 60 and L',
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
  'COEN 20 and L',
  'Computer Science, Data Science Emphasis'
),
(
  'COEN 21 and L',
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
  'COEN 177 and L',
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
(
  'CSCI 10 and L',
  'Computer Science, Software Emphasis'
),
(
  'CSCI 60 and L',
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
  'COEN 20 and L',
  'Computer Science, Software Emphasis'
),
(
  'COEN 21 and L',
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
  'COEN 177 and L',
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
  'COEN 146 and L',
  'Computer Science, Software Emphasis'
),
(
  'CSCI 10 and L',
  'Computer Science, Security Emphasis'
),
(
  'CSCI 60 and L',
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
  'COEN 20 and L',
  'Computer Science, Security Emphasis'
),
(
  'COEN 21 and L',
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
  'COEN 177 and L',
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
),
(
  'CTW 1',
  'Core'
),
(
  'CTW 2',
  'Core'
),
(
  'Advanced Writing',
  'Core'
),
(
  'Ethics',
  'Core'
),
(
  'Diversity',
  'Core'
),
(
  'Arts',
  'Core'
),
(
  'Language 1',
  'Core'
),
(
  'Language 2',
  'Core'
),
(
  'Natural Science',
  'Core'
),
(
  'RTC 1',
  'Core'
),
(
  'RTC 2',
  'Core'
),
(
  'RTC 3',
  'Core'
),
(
  'Social Science',
  'Core'
),
(
  'Culture and Ideas 1',
  'Core'
),
(
  'Culture and Ideas 2',
  'Core'
),
(
  'Culture and Ideas 3',
  'Core'
),
(
  'Civic Engagement',
  'Core'
),
(
  'ELSJ',
  'Core'
);
