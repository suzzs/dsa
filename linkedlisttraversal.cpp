#include<iostream>
using namespace std;
 struct Node
 {
    int data;
    Node* next;
 };

 void traverse(Node* ptr)
 {
    while(ptr !=NULL){
        cout<<"Element:"<<ptr->data<<endl;
        ptr=ptr->next;
    }
 }

  int main()
  {
    Node* head;
    Node* second;
    Node* third;
    head = new Node;
    second= new Node;
    third=new Node;

head->data=7;
head->next=second;

second->data=15;
second->next=third;

third->data=18;
third->next=NULL;

traverse(head);
 return 0;

  }