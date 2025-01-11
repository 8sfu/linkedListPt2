#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include "Student.h"

using namespace std;

bool cmp(char* input, const char* check){
  if(!strcmp(input,(char*)check)){
    return true;
  } else {
    return false;
  }
}

int main(){
  char* input = new char[20];
  bool running = true;

  cout << "Available commands - ADD,QUIT" << endl;
  cin.getline(input,20);
  if(cmp(input,"ADD")){
  }else if(cmp(input,"QUIT")){
    running = false;
  }

  while(running){
    cout << "Available commands - ADD,QUIT,PRINT,DELETE,AVERAGE" << endl;
    if(cmp(input,"ADD")){
    }else if(cmp(input,"PRINT")){
    }else if(cmp(input,"DELETE")){
    }else if(cmp(input,"AVERAGE")){
    }else if(cmp(input,"QUIT")){
      running = false;
    }
  }
  
  delete[] input;
  return 0;
}
