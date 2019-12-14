#include <iostream>
#include "node.h"
#include "student.h"

//Emma Shu, 12/13/2019: Linked list prints student information.

using namespace std;

int main() {
	Student* testStudent = new Student("John","Smith",100000,3.0);
	Node* head = new Node(testStudent);
	Student* testStudent2 = new Student("Jill","Johnson",200000,4.0);
	Node* second = new Node(testStudent2);
	Student* testStudent3 = new Student("Jack","Brown",300000,5.0);
	Node* third = new Node(testStudent3);

	cout << "Head data: ";
	head -> getStudent() -> print(); //Print the current head student info. Tests getStudent() and a student print() function.
	head -> setNext(second); //Set the next node to be the second test node. Tests setNext() function.
	cout << "Second node: ";
	head -> getNext() -> getStudent() -> print(); //Test for getNext().
	second -> setNext(third);
	cout << "Third node: ";
	head -> getNext() -> getNext() -> getStudent() -> print(); //Tests if the nodes are linked correctly by calling to getNext() twice.

	delete head;

	return 0;
}
