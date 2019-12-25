/*
Author: Peter Jin
Date: 12/3/2019
Student Class header
*/

#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

//Constructor
Student::Student(char* first, char* last, int id, float gpa) {
  firstName = first;
  lastName = last;
  this -> id = id;
  this -> gpa = gpa;
}

//Get first name
char* Student::getFirstName() {
  return firstName;
}

//Get last name
char* Student::getLastName() {
  return lastName;
}

//Get id
int Student::getId() {
  return id;
}

//Get gpa
float Student::getGpa() {
  return gpa;
}

//Destructor
Student::~Student() {
  cout << "destructor CALLED" << endl;
  //Nothing to delete (char could be constants)
}
