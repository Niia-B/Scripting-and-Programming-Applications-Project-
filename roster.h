//
//  roster.h
//  Project C867
//
//  Created by Sonia Berrios on 3/8/23.
//

#ifndef roster_h
#define roster_h
#pragma once
#include "student.h"


class Roster
{
public:
    
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];
    
public:
    
    void parse(string row);
    
    void add(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram degreeProgram);
    void PrintAll();
    void printAverageDaysInCourse(string StudentID);
    void printInvalidEmail();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void remove(string studentID);
    
    ~Roster();
};

#endif /* roster_h */
