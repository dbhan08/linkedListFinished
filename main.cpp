#include <iostream>
#include <cstring>
#include "Node.h"
#include "student.h"
#include <iomanip>
using namespace std;

Node* head = NULL;
void add(Node* current, char* first, char* last, int id, float gpa) {
    Student* newStudent = new Student(first, last, id, gpa);
     
    if(current == NULL) {
        head = new Node(newStudent);
        head->setStudent(newStudent);
        
    } else if(current == head && current->getStudent()->getId() >id) {
	Node* nodeStudent = new Node(newStudent);
		nodeStudent->setNext(current);
		nodeStudent->getNext()->setStudent(current->getStudent());
		head = nodeStudent;
		head->setStudent(newStudent);
		

	
	

	

	}  else if(current ->getStudent() ->getId() <  id) {
	Node* nodeStudent = new Node(newStudent);
        while(current->getNext() != NULL) {
	if(current->getNext()->getStudent()->getId() >  id) {
		
		

		nodeStudent->setNext(current->getNext());
		nodeStudent->getNext()->setStudent(current->getNext()->getStudent());
		
		break;
	 
	
	}
            current = current->getNext();
	}
        current->setNext(nodeStudent);
	current ->getNext() -> setStudent(newStudent);
	
        
        
    }  else {

	add(current->getNext(), first, last, id, gpa);

} 



}




float getAverage(Node* current) {
float total = 0;
int count = 0;

if(current == head) {
total+= current->getStudent()->getGpa();
count++;
}

while(current->getNext()!=NULL) {
total+=current->getStudent()->getGpa();
count++;
current = current->getNext();

}
return total;

}

void remove(Node* current,Node* prev, int id) {
if(current == NULL) {
return;

}
if(current->getStudent()->getId() == id) {
if(prev == NULL) {
if(current->getNext() != NULL) {
cout << "n" << endl;

head = current->getNext();
current -> ~Node();
} else {

current -> ~Node();
head = NULL;
}
return;

}


else if(current->getNext() == NULL) {
cout << "a";
Node* temp = new Node(current->getStudent());
temp = current; 
prev->setNext(NULL);
current -> ~Node();
return;
} else {
cout << "c";
Node* temp = new Node(current->getStudent());
temp = current;
prev->setNext(current->getNext());
current -> ~Node();
return;
}





} else {
prev= current;
current = current->getNext();
remove(current,prev,id);


}

}


    
    




void print(Node* next) {
    if(next == head) {
        cout << "list: ";
    }
    if(next != NULL) {
        cout << next->getStudent()->getFirst() << " " << next->getStudent()->getLast() << "\t"<< next ->getStudent()->getId() << "\t" <<
       fixed << setprecision(2)<< next ->getStudent()-> getGpa() << endl;
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
		Node* current = head;
                add(current,first,last,id,gpa);
                
            } else if(strcmp(inp,"print") == 0) {
                print(head);
                
            }else if(strcmp(inp, "quit") == 0) {
                
                running = false;
	    } else if(strcmp(inp,"avg") == 0) {
		cout << "The average gpa is: " << getAverage(head) << endl;

		} else if(strcmp(inp,"delete") == 0) { 
			cout << "Enter the id of the student you would like to delete" << endl;
			cin >> id;
			Node* current = head;
			remove(current,NULL ,id);

		}    else {
                
                cout << "Enter a valid option" << endl;
            }
            
        }
        return 0;
        
    }









