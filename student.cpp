#include <iostream>
#include "student.h"
#include <cstring>

using namespace std;

Student::Student(char* first, char* last, int newId, float newgpa) {
    strcpy(firstName,first);
	strcpy(lastName,last);	
    
	

    Id = newId;
    gpa = newgpa;
    
}


 


Student::~Student() {
    delete &firstName;
    delete &lastName;
    
}

char* Student::getFirst() {
    return firstName;
    
}

char* Student::getLast() {
    return lastName;
    
}

int Student::getId() {
    return Id;
    
}

float Student::getGpa() {
    return gpa;
    
}
