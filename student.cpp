#include<iostream>
#include "student.h"
#include <cstring>

using namespace std;

Student::Student(char* firstName, char* secondName, int id, float gpa) {
	this->firstName = new char[strlen(firstName)+1];
	strcpy(this->firstName, firstName); //Allocates just enough memory for the names.
	this->secondName = new char[strlen(secondName)+1];
	strcpy(this->secondName, secondName);
	this-> id = id;
	this->gpa = gpa;
}

Student::~Student() {
	delete []firstName;
	delete []secondName;
}

void Student::print() {
	cout << firstName << " " << secondName << ", " << id << ", " << gpa << endl;
}
