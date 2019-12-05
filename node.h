#pragma once
#include <iostream>

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
};
