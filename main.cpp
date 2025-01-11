#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include "Student.h"
#include "Node.h"

using namespace std;

Node* addNode(Node* listHead, Node* currentNode, Node* newNode){
  int currentID = ((*currentNode).getStudent())->getID(); 
  int checkID = ((*newNode).getStudent())->getID();
  if(currentNode == listHead){
    if(currentID > checkID){ //New node should be list head
      newNode->setNext(currentNode); //Set new node to new list head
      return newNode;
    } else {
      if(listHead->getNext() == nullptr){ //If the list is two long, add new node next
	listHead->setNext(newNode);
	return listHead;
      } else { //Otherwise recurse thru to the end
	addNode(listHead,listHead->getNext(),newNode);
      }
    }    
  } else { //New node isn't list head
    if(currentID < checkID){ //Check all nodes to see if new node goes after them
      newNode->setNext(currentNode->getNext()); //Insert new node into list
      currentNode->setNext(newNode);
      return listHead;
    }
  }
  return listHead;
}

Node* deleteNode(Node* listHead, Node* currentNode, int* id){
  int currentID = ((*currentNode).getStudent())->getID();
  int checkID = *id;
  if(currentNode == listHead){
    int currentID = ((*currentNode).getStudent())->getID();
    if(currentID == checkID){ //new list head is next node
      Node* placeholderNode = listHead->getNext();
      listHead = placeholderNode;
      return listHead;
    } else if (currentNode->getNext() != nullptr) { //if second node exists
      int nextCaseID = ((*(*listHead).getNext()).getStudent())->getID();
      if(nextCaseID == checkID){ //if second node is to be deleted
	listHead->setNext((*(*listHead).getNext()).getNext());
	return listHead;
      } else { //recurse thru list
	deleteNode(listHead,listHead->getNext(),id);
      }
    } else { //delete whole list
      return nullptr;
    }
  } else if (currentNode->getNext() != nullptr) { //check other nodes in list
    int currentID = ((*(*currentNode).getNext()).getStudent())->getID();
    if(checkID == currentID){
      currentNode->setNext(((*(*currentNode).getNext()).getNext()));
      return listHead;
    }
  } else {
    cout << "There is no student with that name." << endl;
  }
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
