/*
Author: Peter Jin
Date: 12/3/2019
Student Class Header
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Student {

 public:

  //Constructor
  Student(char*, char*, int, float);

  //Get first name
  char* getFirstName();

  //Get last name
  char* getLastName();

  //Get id
  int getId();

  //Get gpa
  float getGpa();

  //Destructor
  ~Student();
  
 private:

  char* firstName;
  char* lastName;
  int id;
  float gpa;

};

#endif
