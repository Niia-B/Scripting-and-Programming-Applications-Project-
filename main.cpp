//
//  main.cpp
//  Project C867
//
//  Created by Sonia Berrios on 2/28/23.
//
#pragma once
#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
using namespace std;


int main(int argc, const char * argv[])
{
    cout << " Course: C867 Scripting and Programing Application " << endl;
    cout << " Programing Language: C++ " << endl;
    cout << " Student ID: 010765039 " << endl;
    cout << " Name: Sonia Berrios " << endl;
    cout << endl;
    
    const string studentData[] =
    
    {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Sonia,Berrios,sberri6@wgu.edu, 30,20,30,40,SOFTWARE"
        
    };
    
    
    const int numStudents = 5;
    Roster classRoster;
    
    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    
    cout << "Class Roster:"  << std::endl;
    classRoster.PrintAll();
    cout <<  std::endl;
    
    
    cout << "Displaying Invalid Emails:" << std::endl;
    classRoster.printInvalidEmail();
    cout << std::endl;
    
    cout << "Average days in course:" << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
    classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << std::endl;
    
    cout << "Program Degree Display" <<degreeProgramStrings[2] << std::endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << std::endl;
    
    
    cout << "Remove A3" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    
    cout << "Remove A3" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    
    system("pause");
    return 0;
}
