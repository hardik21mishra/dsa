//linked list 
// LL insertion at tail 

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void InsertAtTail(Node* &tail, int d) // d is data btw 
{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}  

void InsertAtHead(Node* &head, int d){
    //new node create
    Node* temp = new Node(d);
    
    //create ki hui node ko pehle wale ke data pe point pe point krado, abhi yeh null pe pointed hai
    temp -> next = head;
    
    // now there are two LL connected so head has to be shifted to first node head since we inserted at the beginning in this program
    head = temp;
    
}   

void print(Node* &tail){
    // we will learn to traverse a LL here
    // make a copy variable temp to not make any changes in original 
    
    Node* temp = tail;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}
int main(){
    //created a new node
    Node* node1 = new Node(10);
    // //cout<< node1 -> data <<endl;
    // //cout << node1 -> next << endl;

    // head pointed to node1
    Node* head = node1;
    Node* tail = node1; //(when single node: head and tail will be same )
    print(head);
    
    InsertAtTail(tail, 12);

    print(head);

    InsertAtTail(tail, 15);
    print(head);

   
    return 0;
} 