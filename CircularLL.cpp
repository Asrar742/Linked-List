#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val){
     
        data = val;
        next=NULL;
    }    
};

class circularLL{
    Node* head;
    Node* tail;
    public:
    circularLL(){
    head = tail =NULL;
    }

    void insertathead (int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head=tail=newNode;
            tail->next=head;
        }else{
            newNode->next = head;
            head = newNode;
            tail->next=head;
        }
        
        }
        void insertattail(int val){
            Node* newNode = new Node(val);
            if (head==NULL){
               head = tail = newNode;
               tail->next=head;
            }else{
                newNode->next= head;
                tail->next=newNode;
                tail=newNode;
            }
    }
    void deleteathead(){
        if(head==NULL){
            delete head;
        } else if (head==tail){
            delete head;
            head=tail=NULL;
        }
        Node* temp = head;
        head = head->next;
        tail->next=head;
        temp -> next = NULL;
        delete temp;
    }

    void deleteattail (){
         if(head==NULL){
            delete head;
        } else if (head==tail){
            delete head;
            head=tail=NULL;
        }
        Node* temp=tail;
        Node* prev = head;
        while(prev->next!=tail){
        prev = prev -> next;
    }
    tail=prev;
    tail->next = head;
    temp->next = NULL;
    delete temp;
}

    void display(){
        if(head==NULL) return;
       
        cout<<head->data<<"->";
        Node* temp=head->next;
        while (temp!=head){
           cout<<temp->data<<"->";
           temp= temp->next;
        }
        //cout<< temp->data << endl;
        
    }
};

int main(){
    circularLL cll;

    cll.insertathead(1);
    cll.insertathead(2);
    cll.insertathead(3);
    cll.insertattail(4);
    cll.insertattail(5);
    cll.insertattail(6);
    //cll.deleteathead();
    //cll.deleteattail();

    cll.display();
    cout<<" ";

    cll.deleteathead();
    cll.display();
    cout<<" ";

    cll.deleteattail();
    cll.display();
    return 0;

};