/*
Author: Peter Jin
Date: 12/22/19
Node cpp class to test whether its node.o's fault
(Not compiled unless for debug purposes)
*/

#include <iostream>
#include "student.h"
#include "node.h"

using namespace std; 

Node::Node(Student* student) {
  this->student = student;
  this->next = NULL;
}

Node::~Node() {
  cout << "Node deconstructor call" << endl;
  if(student) {
    cout << " deletg studetn: " << student -> getId() << endl; 
    delete student;
  }
}

Node* Node::getNext() {
  return next;
}

Student* Node::getStudent() {
  return student;
}

void Node::setNext(Node* next) {
  this ->next = next;
}

