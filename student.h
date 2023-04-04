//
//  student.h
//  Project C867
//
//  Created by Sonia Berrios on 3/8/23.
//
#pragma once
#ifndef student_h
#define student_h
#include <iostream>
#include <iomanip>
#include "degree.h"
using namespace std;

class Student
{
public:
    const static int daystoComplete = 3;
    
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int days[daystoComplete];
    DegreeProgram degreeProgram;
    
public:
    Student(); //constructor
    Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram);
    ~Student(); //destructor
    
    
    //accessors
    string getStudentID();
    string getFirstname();
    string getLastname();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getDegreeProgram();
    
 //mutatator
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    static void printHeader();
    
    void print();
    
};

#endif /* student_h */
