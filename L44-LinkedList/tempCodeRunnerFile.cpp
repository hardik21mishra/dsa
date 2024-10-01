#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node(){
        int val = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for node and data "<<" "<<val;
    }
};


// traversing LL
void print(Node* head){
    Node* temp = head;
    
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

// gives length of linked list
int getLen(Node* head){
    int len = 0;
    Node* temp = head;
    
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }

    return len;
}

// inserting at head -- see my handwritten notes for visualization
void InsertAtHead(Node* &head, Node* &tail,  int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

}
// inserting at tail -- see my handwritten notes for visualization
void InsertAtTail(Node* &head, Node* &tail, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(data);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void InsertAtPosition(Node* &head, Node* &tail, int position, int data){
    if(position == 1){
        InsertAtHead(head, tail, data);
        return;
    }
    
    Node* temp = head;
    int cnt = 1;
    while(cnt < position - 1 && temp != NULL){
        temp = temp -> next;
        cnt++;
    }
    // insertion at tail
    if(temp -> next == NULL){
        InsertAtTail(head, tail, data);
        return;
    }

    // creating a node to insert at position
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}


void DeleteNode(Node* &head, int position){
    // deleting starting node
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        // deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}
int main(){
    
    Node* head = NULL;
    
    Node* tail = NULL;

    // print(head);
    // cout<<getLen(head)<<endl;;

    InsertAtHead(head, tail, 11);
    print(head);

    InsertAtTail(head, tail, 25);
    print(head);

    InsertAtPosition(head, tail, 3, 88);
    print(head);

    InsertAtPosition(head, tail, 4, 89);
    print(head);

    DeleteNode(head, 1);
    print(head);
    return 0;
}