/*
Author: Peter Jin
Date: 12/18/19
Student Linked List main
*/

#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

bool parse(char*, Node*&);
void add(Node*&);
void addNode(Node*&, Student*);
void del(Node*&);
bool delNode(Node*&, int);
void print(Node*);
void printStudent(Student*);
void printAvg(Node*);

using namespace std;

int main() {
  cout.setf(ios::showpoint);
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);
  
  cout << "Welcome to student list" << endl;
  Node* head = NULL;
  bool running = true;
  while (running) {
    cout << "Enter a command. Type \"h\" for help." << endl;
    char* input = new char();
    cin.get(input, 40);
    cin.clear();
    cin.ignore();
    running = parse(input, head);
    cout << endl << "___________________________________________________" << endl << endl;
  }
  cout << "Thanks for using studentlist." << endl;
}

bool parse(char* input, Node* &head) {
  for (int i = 0; i < strlen(input); i++) {
    input[i] = tolower(input[i]);
  }
  
  if (strcmp(input, "h") == 0) {
    cout << "Commands: " << endl;
    cout << "Add: add a student" << endl;
    cout << "Delete: delete a student by id" << endl;
    cout << "Print: print all students in list" << endl;
    cout << "Average: print average gpa of students in list" << endl;
    cout << "Quit: exit from studentlist program" << endl;
  } else if (strcmp(input, "add") == 0) {
    add(head);
  } else if (strcmp(input, "delete") == 0) {
    del(head);
  } else if (strcmp(input, "print") == 0) {
    if (head == NULL) {
      cout << "Student list is empty" << endl;
      return true;
    }
    print(head);
  } else if (strcmp(input, "average") == 0) {
    printAvg(head);
  } else if (strcmp(input, "quit") == 0) {
    return false;
  } else {
    cout << "Sorry, command not recognized." << endl;
  }
  return true;
}

void add(Node* &head) {
  char* first = new char();
  char* last = new char();
  int id = 0;
  float gpa = 0;
  cout << "Please enter student first name" << endl;
  cin.get(first, 25);
  cin.get();
  cout << "Please enter student last name" << endl;
  cin.get(last, 35);
  cin.get();
  cout << "Please enter student id" << endl;
  cin >> id;
  cin.clear();
  cin.ignore();
  cout << "Please enter student gpa" << endl;
  cin >> gpa;
  cin.clear();
  cin.ignore();
  addNode(head, new Student(first, last, id, gpa));
}

void del(Node* &head) {
  cout << "Please enter id to delete" << endl;
  int id = 0;
  cin >> id;
  cin.clear();
  cin.ignore();
  if(delNode(head, id)) cout << "Student removed from list" << endl;
  else cout << "Student not found" << endl;
}

void print(Node* head) {
  if (head == NULL) return;
  printStudent(head -> getStudent());
  cout << endl;
  print(head -> getNext());
}

void printStudent(Student* s) {
  cout << "Student: " << s -> getFirstName() << " " << s -> getLastName() << endl;
  cout << "Id: " << s -> getId() << endl;
  cout << "Gpa: " << s -> getGpa() << endl;
}

void printAvg(Node* head) {
  if (head == NULL) {
    cout << "Student list is empty" << endl;
  }
  float tot;
  int ct;
  while (head != NULL) {
    tot += head -> getStudent() -> getGpa();
    ct ++;
  }

  cout << "Average gpa is " << tot/ct << "." << endl;
}

void addNode(Node* &head, Student* s) {
  if (head == NULL) {
    head = new Node(s);
    return;
  }
  if (head -> getStudent() -> getId() > s -> getId()) {
    Node* temp = head;
    head = new Node(s);
    head -> setNext(temp);
    return;
  }
  if (head -> getNext() == NULL) {
    Node* temp = new Node(s);
    head -> setNext(temp);
    return;
  }
  if (head -> getNext() -> getStudent() -> getId() > s -> getId()) {
    Node* temp = new Node(s);
    temp -> setNext(head -> getNext());
    head -> setNext(temp);
    return;
  }
  Node* next = head->getNext();
  addNode(next, s);
}

bool delNode(Node* &head, int id) {
  if (head == NULL) {
    return false;
  }
  if (head -> getStudent() -> getId() == id) {
    Node* temp = head;
    head = head -> getNext();
    delete temp;
    return true;
  }
  if (head -> getNext() == NULL) {
    return false;
  }
  if (head -> getNext() -> getStudent() -> getId() == id) {
    Node* temp = head -> getNext();
    head -> setNext(head -> getNext() -> getNext());
    delete temp;
    return true;
  }
  Node* next = head -> getNext();
  return delNode(next, id);
}
