#pragma once
#include <iostream>

using namespace std;

class Student {
	public:
		Student(char* firstName, char* secondName, int id, float gpa);
		virtual ~Student();
		void print();
	private:
		char* firstName;
		char* secondName;
		int id;
		float gpa;
};		
