#include <iostream>
#include <cstring>
#include "Node.h"
#include "student.h"
using namespace std;

Node* head = NULL;
void add(char* first, char* last, int id, float gpa) {
    Student* newStudent = new Student(first, last, id, gpa);
    Node* current = head;
    if(current == NULL) {
        head = new Node(newStudent);
        head->setStudent(newStudent);
        
    } else {
        while(current->getNext() != NULL) {
            current = current->getNext();
            
        }
        current->setNext(new Node(newStudent));
        current->getNext()->setStudent(newStudent);
    }
    
    
}


void print(Node* next) {
    if(next == head) {
        cout << "list: ";
    }
    if(next != NULL) {
        cout << next->getStudent()->getFirst() << " " << next->getStudent()->getLast() << "\t"<< next ->getStudent()->getId() << "\t" <<
        next ->getStudent()-> getGpa() << endl;
        print(next->getNext());
        
    }
}
    int main() {
        bool running = true;
        char inp[20];
        char first[20];
        
        char last[20];
        
        int id;
        float gpa;
        
        while(running) {
           cout << "Enter what you would like to do" << endl; 
            cin.get(inp,20);
            cin.clear();
            cin.ignore();
            if(strcmp(inp, "add") == 0) {
                cout << "Enter a first name: " << endl;
                cin.get(first, 20);
                cin.clear();
                cin.ignore();
                cout << "Enther their last name: " << endl;
                cin.get(last,20);
                cin.clear();
                cin.ignore();
                cout << "Enter their id: " << endl;
                cin >> id;
                cin.clear();
                cin.ignore();
                cout << "Enter their gpa: " << endl;
                cin >> gpa;
                cin.clear();
                cin.ignore();
                add(first,last,id,gpa);
                
            } else if(strcmp(inp,"print") == 0) {
                print(head);
                
            }else if(strcmp(inp, "quit") == 0) {
                
                running = false;
            } else {
                
                cout << "Enter a valid option" << endl;
            }
            
        }
        return 0;
        
    }









