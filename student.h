#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student {
 public:
  Student();
  char* getName();
  int getID();
  float getGPA();
 private:
  char firstname[20];
  char lastname[20];
  long id;
  float gpa;
};

#endif
