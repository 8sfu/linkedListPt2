#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student {
 public:
  Student();
  char* getfirstName(); //Actually gets full name but named inaccurately for compatibility with Node.cpp and Node.h
  int getID();
  float getGPA();
 private:
  char firstname[20];
  char lastname[20];
  long id;
  float gpa;
};

#endif
