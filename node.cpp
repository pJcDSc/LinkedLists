#include <iostream>
#include "student.h"
#include "node.h"

using namespace std;

Node::Node(Student* student) {
	this->student = student;
	this->next = NULL; //Sets next as NULL until a pointer is assigned.
}

Node::~Node() { //Makes sure that the destructor does not delete a NULL.
	if (student) {
		delete student;
	}
	if (next) {
		delete next;
	}
}

void Node::setNext(Node* next) {
	this->next = next;
}

Node* Node::getNext() {
	return next;
}

Student* Node::getStudent() {
	return student;
}
