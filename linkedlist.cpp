#include<iostream>
using namespace std;

 class Node {
    public:
    int data;
    Node* next;

    Node (int val){
        data = val;
        next = NULL;
    }
 };
 class list {
    Node* head;
    Node* tail;
    public:
    list(){
        head = tail = NULL;
    }
    void Push_front (int val){
        Node* newNode = new Node(val);
        if (head==NULL){
            head = tail = newNode;
            return;

        } else {
            newNode -> next = head;
            head = newNode;
        }
        
    }
    void Push_back (int val){
    Node* newNode = new Node(val);
    if (head == NULL){
        head = tail = newNode;
    } else{
        tail->next = newNode;
        tail = newNode;
    }
    }

    void Pop_front(){
        //Node* newNode = new Node (val); dont need a newnode while deleting one.
        if (head == NULL){
            cout<<"LL is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }
    void Pop_back (){
        if (head==NULL){
            cout<<"LL is empty"<<endl;
        
        return ; 
     }      
        
        if (head==tail){
            delete head;
            head = tail = NULL;
            return;
        }
    
    Node* temp = head;
    while(temp->next !=tail){
        temp= temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
}

    void printll(){
        Node* temp = head;

        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"Null"<<endl;
    }
    
 };
 int main(){
    list ll;
    ll.Push_front(1);
    ll.Push_front(2);
    ll.Push_front(3);
    ll.Pop_back();
    ll.printll();
  return 0;
 }