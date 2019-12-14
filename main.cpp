#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

int main() {
	Student* testStudent = new Student("John","Smith",100000,3.0);
	Node* head = new Node(testStudent);
	Student* testStudent2 = new Student("Jill","Johnson",200000,4.0);
	Node* second = new Node(testStudent2);
	Student* testStudent3 = new Student("Jack","Brown",300000,5.0);
	Node* third = new Node(testStudent3);

	cout << "Head data: ";
	head -> getStudent() -> print();
	head -> setNext(second);
	cout << "Second node: ";
	head -> getNext() -> getStudent() -> print();
	second -> setNext(third);
	cout << "Third node: ";
	head -> getNext() -> getNext() -> getStudent() -> print();

	delete head;

	return 0;
}
