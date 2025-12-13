#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }

    
};

class doublelist{

    Node* head;
    Node* tail;
    public:
    doublelist() {
        head = tail = NULL;
    }
void push_front(int val){
        Node* newnode = new Node (val);
        if (head==NULL){
            head = tail = newnode;
        }else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }
    void display (){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<< "<=>";
            temp= temp->next;
        }
        cout<<"Null\n";
    }
};

int main(){

    doublelist dll;
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_front(4);

    dll.display();

    return 0;
}   