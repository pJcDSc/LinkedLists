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
  //Configure cout to print 2 decimal points
  cout.setf(ios::showpoint);
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);
  
  cout << "Welcome to student list" << endl;
  Node* head = NULL; //Beginning of linked list
  bool running = true;
  //Main program loop to read and parse input
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

//Parse function that takes input and calls other functions based on input
bool parse(char* input, Node* &head) {
  for (int i = 0; i < strlen(input); i++) {
    input[i] = tolower(input[i]);
  }
  if (strcmp(input, "h") == 0) { //help command
    cout << "Commands: " << endl;
    cout << "Add: add a student" << endl;
    cout << "Delete: delete a student by id" << endl;
    cout << "Print: print all students in list" << endl;
    cout << "Average: print average gpa of students in list" << endl;
    cout << "Quit: exit from studentlist program" << endl;
  } else if (strcmp(input, "add") == 0) { //add command
    add(head);
  } else if (strcmp(input, "delete") == 0) { //delete command
    del(head);
  } else if (strcmp(input, "print") == 0) { //print command
    if (head == NULL) {
      cout << "Student list is empty" << endl;
      return true;
    }
    print(head);
  } else if (strcmp(input, "average") == 0) { //average command
    printAvg(head);
  } else if (strcmp(input, "quit") == 0) { //quit command
    return false;
  } else { //command not known
    cout << "Sorry, command not recognized." << endl;
  }
  return true;
}

//Add function to take user input and make new student
void add(Node* &head) {
  //take inputs from ser
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
  //Add a new student to the linkedlist based on user input
  addNode(head, new Student(first, last, id, gpa));
}

//Delete command to read id and call recursive delete function
void del(Node* &head) {
  //read user input for id to delete
  cout << "Please enter id to delete" << endl;
  int id = 0;
  cin >> id;
  cin.clear();
  cin.ignore();
  //Delete node from list if found
  if(delNode(head, id)) cout << "Student removed from list" << endl;
  else cout << "Student not found" << endl;
}

//recursive print function to print every student using helper function printStudent
void print(Node* head) {
  if (head == NULL) return;
  //Print the student in the node
  printStudent(head -> getStudent());
  cout << endl;
  //Try to print next node
  print(head -> getNext());
}

//Takes student and prints values in student
void printStudent(Student* s) {
  cout << "Student: " << s -> getFirstName() << " " << s -> getLastName() << endl;
  cout << "Id: " << s -> getId() << endl;
  cout << "Gpa: " << s -> getGpa() << endl;
}

//Loop through list to get average gpa
void printAvg(Node* head) {
  if (head == NULL) {
    cout << "Student list is empty" << endl;
    return;
  }
  float tot = 0;
  int ct = 0;
  //While not at end of list
  while (head != NULL) {
    tot += head -> getStudent() -> getGpa();
    ct ++;
    head = head -> getNext();
  }

  cout << "Average gpa is " << tot/ct << "." << endl;
  return;
}

//Recursive function to add node to list in order
void addNode(Node* &head, Student* s) {
  if (head == NULL) {
    head = new Node(s);
    return;
  }
  //if current node id is greater than adding student id then add it before current node
  if (head -> getStudent() -> getId() > s -> getId()) {
    Node* temp = head;
    head = new Node(s);
    head -> setNext(temp);
    return;
  }
  //if nothing after head just add after head
  if (head -> getNext() == NULL) {
    Node* temp = new Node(s);
    head -> setNext(temp);
    return;
  }
  //if next is greater than adding student id add before next
  if (head -> getNext() -> getStudent() -> getId() > s -> getId()) {
    Node* temp = new Node(s);
    temp -> setNext(head -> getNext());
    head -> setNext(temp);
    return;
  }
  //try adding, setting current node to next node
  Node* next = head->getNext();
  addNode(next, s);
}

//Recursive delete function
bool delNode(Node* &head, int id) {
  //If list empty do nothing
  if (head == NULL) {
    return false;
  }
  //If current node matches deletion id just delete
  if (head -> getStudent() -> getId() == id) {
    Node* temp = head;
    head = head -> getNext();
    delete temp;
    return true;
  }
  //Otherwise if there is nothing after return false (id not found)
  if (head -> getNext() == NULL) {
    return false;
  }
  //Otherwise if next student matches id delete next, set current.next to be next next node (can be null)
  if (head -> getNext() -> getStudent() -> getId() == id) {
    Node* temp = head -> getNext();
    head -> setNext(head -> getNext() -> getNext());
    delete temp;
    return true;
  }
  //Otherwise try again with next node
  Node* next = head -> getNext();
  return delNode(next, id);
}
