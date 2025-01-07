#include "student.h"
#include <cstring>

using namespace std;

Student::Student(){
  cout << "Enter this student's " << endl;
  cout << "Name - ";
  cin.getline(firstname,20);
  cout << "Surname - ";
  cin.getline(lastname,20);
  cout << "ID - ";
  cin >> id;
  cin.ignore();
  cout << "GPA - ";
  cin >> gpa;
  cin.ignore();
}

char* Student::getName(){
  return strcat(strcat(firstname,(char*)" "),lastname);
}

int Student::getID(){
  return id;
}

float Student::getGPA(){
  return gpa;
}

