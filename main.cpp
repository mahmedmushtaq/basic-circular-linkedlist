#include <iostream>
using namespace std;

class node{
  public:
  int value;
  node *next;
};

class CircularLinkedList{
   node *head, *top;
   int size;
   public:
     CircularLinkedList(){
       head = NULL;
       top = NULL;
     }

     void push(int value){
       node *newNode;
       newNode = new node();
       newNode->value = value;
       size++;
       if(head == NULL){
         head = newNode;
         newNode->next = head;
         top = newNode;
       }else{
         // previous next is
         top->next = newNode;
         newNode->next = head;
         top = newNode;
       }
     }

     void display(){
       node *temp = head;
       int i = 0;
       while(i < size){
         cout << temp->value;
         temp = temp->next;
         i++;

       }
     }

     void deleteNode(int position){
       if(head == NULL){
         cout << "List is empty";
         return;
       }

       if(position == 0){
         // if only one item is present
          node *temp = head;
          head = head->next;
          delete temp;
          size--;
          return;

       }

       node *temp = head;
       node *prevNode, *nextNode;
       int i= 0;
       while( i < size){
         
          if((i+1) == position){
             prevNode = temp;
             nextNode = temp->next;
             size--;
          }
          temp = temp->next;
          i++;
          
       }

       prevNode->next = nextNode->next;
       delete nextNode; 
        

     }
};

int main() {
   CircularLinkedList list;
   list.push(2);
   list.push(3);
   list.push(4);
   list.deleteNode(2);
   list.display();
}