#pragma once
#include <iostream>
#include "student.h"

//Emma Shu, 12/13/2019: The header file of the linked list nodes.

using namespace std;

class Node {
	public:
		Node(Student* student);
		virtual ~Node();
		void setNext(Node* next);
		Node* getNext();
		Student* getStudent();
	private:
		Student* student;
		Node* next;
};
