#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include "Student.h"
#include "Node.h"

using namespace std;

Node* addNode(Node* listHead, Node* currentNode, Node* newNode){
  int checkID = ((*newNode).getStudent())->getID();
  if(currentNode == listHead){ //setting to new list head
    int currentID = ((*listHead).getStudent())->getID();
    if(checkID < currentID){
      newNode->setNext(currentNode);
      return newNode;
    }
  }
  if (currentNode->getNext() == nullptr){ //appending to end of list
    currentNode->setNext(newNode);
    return listHead;
  } else { //inserting in middle of list
    int currentNextID = ((*((*currentNode).getNext())).getStudent())->getID();
    if(checkID < currentNextID){
      newNode->setNext(currentNode->getNext());
      currentNode->setNext(newNode);
      return listHead;
    } else {
      addNode(listHead,currentNode->getNext(),newNode);
    }
  }  
  return listHead;
}

Node* deleteNode(Node* listHead, Node* currentNode, int* id){
  int checkID = *id;
  if(currentNode == listHead){
    int currentID = ((*currentNode).getStudent())->getID();
    if(currentID == checkID){ //new list head is next node
      return listHead->getNext();
    }
  }
  if (currentNode->getNext() != nullptr) { //check next node
    int currentNextID = ((*(*currentNode).getNext()).getStudent())->getID();
    if(checkID == currentNextID){
      currentNode->setNext(((*(*currentNode).getNext()).getNext()));
      return listHead;
    }
  } //continue recursing through list
  deleteNode(listHead,currentNode->getNext(),id);
  return listHead;
}

bool cmp(char* input, const char* check){
  if(!strcmp(input,(char*)check)){
    return true;
  } else {
    return false;
  }
}

void printList(Node* node){
  if(node != nullptr){
    cout << ((*node).getStudent())->getFirstName() << " " << ((*node).getStudent())->getLastName() << " (ID:" << ((*node).getStudent())->getID() << ") (GPA: " << ((*node).getStudent())->getGPA() << ") " << endl;
    printList(node->getNext());
  } else {
    cout << endl;
  }
  return;
}

int main(){
  char* input = new char[20];
  bool running = true;
  Node* listHead = nullptr;
  Node* currentNode;

  while(running){
    if(listHead == nullptr){
      cout << endl << "Available commands - ADD,QUIT" << endl;
      cin.getline(input,20);
      
      if(cmp(input,"ADD")){
	listHead = new Node(new Student());
      }else if(cmp(input,"QUIT")){
      running = false;
      }
    } else { //List manipulation available if lists exists
      cout << endl << "Available commands - ADD,QUIT,PRINT,DELETE,AVERAGE" << endl;
      cin.getline(input,20);
      if(cmp(input,"ADD")){
	listHead = addNode(listHead,listHead,new Node(new Student()));
      }else if(cmp(input,"PRINT")){
	printList(listHead);
      }else if(cmp(input,"DELETE")){
	cout << "Who would you like to delete?" << endl;
	int id;
	cin >> id;
	cin.ignore();
	listHead = deleteNode(listHead,listHead,&id);
      }else if(cmp(input,"AVERAGE")){
      }else if(cmp(input,"QUIT")){
	running = false;
      }
    }
  }
  
  cout << endl;
  delete[] input;
  return 0;
}
