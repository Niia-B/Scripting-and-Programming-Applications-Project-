//
//  roster.cpp
//  Project C867
//
//  Created by Sonia Berrios on 2/28/23.
//
#pragma once
#include "roster.h"
#include <iostream>
#include <string>
using namespace std;


void Roster::parse(string studentData)
{
    DegreeProgram degreeProgram = SECURITY;
    if (studentData.back() == 'K') degreeProgram = NETWORK;
    else if (studentData.back() == 'E') degreeProgram = SOFTWARE;
    
    int rhs = studentData.find(",");
    string studentID = studentData.substr(0,rhs);
    
    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs +1;
    rhs = studentData.find(",", lhs);
    string email = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs +1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs +1;
    rhs = studentData.find(",", lhs);
    int days1 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs +1;
    rhs = studentData.find(",", lhs);
    int days2 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs +1;
    rhs = studentData.find(",", lhs);
    int days3 = stoi(studentData.substr(lhs, rhs - lhs));
    
    
    add(studentID, firstName, lastName, email, age, days1, days2, days3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram degreeProgram)
{
    int days[3] = { days1, days2, days3 };
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, days, degreeProgram);
}

void Roster::PrintAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i] !=nullptr || classRosterArray[i] != 0)
        {
            classRosterArray[i]->print();
            
        }
        
    }
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            cout << studentID <<":";
            cout << (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2])/3 << std::endl;
        }
    }
}

void Roster::printInvalidEmail()
{
    bool any = false;
    for (int i =0; i <= Roster::lastIndex; i++)
    {
        string email = (classRosterArray[i]->getEmail());
        if (email.find('@') == string::npos || (email.find('.') == string::npos) || (email.find(' ') != string::npos))
        {
            any = true;
            cout << email << ": " << classRosterArray[i]->getEmail()<<std::endl;
        }
        if (!any) cout << "NONE" << std::endl;
    }
}
    
    
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
        for (int i = 0; i <= Roster::lastIndex; i++)
        {
            if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
        }
        cout <<std::endl;
    }
    
    
void Roster::remove(string studentID)
    {
        bool success = false;
        for (int i = 0; i <= Roster::lastIndex; i++)
        {
            if (classRosterArray[i]->getStudentID() ==  studentID)
            {
                success = true;
                if (i < numStudents - 1)
                {
                    Student* temp = classRosterArray [i];
                    classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
            }
        }
    if (success)
    {
        cout << studentID << " removed from roster." << std::endl << std::endl;
        this->PrintAll();
    }
    else cout << studentID << " studentID not found. " <<std::endl << std::endl;
    }
    
Roster::~Roster()
{
    cout << "Destructor Declared " << std::endl << std::endl;
    for ( int i = 0; i <numStudents; i++)
    {
        cout << "Destroying student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
        
    }
};
