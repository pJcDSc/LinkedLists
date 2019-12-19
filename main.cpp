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

bool delNode(Node* &head, int id) {
  cout << "new" << endl;
  cout << head << endl;
  cout << head -> getNext() << endl;
						
  //only if list is empty
  if (head == NULL) {
    return false;
  }
  //only if actual head contains student to delete
  if (head -> getStudent() -> getId() == id) {
    Node* temp = head;
    head = head -> getNext();
    delete temp; //can't figure out how to delete without segfault
    return true;
  }
  //
  if (head -> getNext() == NULL) {
    return false;
  }
  if (head -> getNext() -> getStudent() -> getId() == id) {
    Node* temp = head -> getNext();
    head -> setNext(head -> getNext() -> getNext());
    delete temp; // can't figure out how to delete without segfault
    return true;
  }
  Node* next = head -> getNext();
  return delNode(next, id);
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

}

void addNode(Node* &head, Student* s) {
  cout << s << endl;
  if (head == NULL) {
    head = new Node(s);
    return;
  }
  if (head -> getNext() == NULL) {
    Node* temp = new Node(s);
    head -> setNext(temp);
    return;
  }
  Node* next = head->getNext();
  addNode(next, s);
}
