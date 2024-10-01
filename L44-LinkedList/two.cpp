//linked list 
// LL insertion at head

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

void InsertAtHead(Node* &head, int d){
    //new node create
    Node* temp = new Node(d);
    
    //create ki hui node ko pehle wale ke data pe point pe point krado, abhi yeh null pe pointed hai
    temp -> next = head;
    
    // now there are two LL connected so head has to be shifted to first node head since we inserted at the beginning in this program
    head = temp;
    cout<<endl;
}   

void print(Node* &head){
    // we will learn to traverse a LL here
    // make a copy variable temp to not make any changes in original 
    
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
int main(){
    //created a new node
    Node* node1 = new Node(10);
    // //cout<< node1 -> data <<endl;
    // //cout << node1 -> next << endl;

    // head pointed to node1
    Node* head = node1;
    print(head); // o/p: 10
    
    InsertAtHead(head, 12); //12 daal dia

    print(head); // o/p: 12 10

    InsertAtHead(head, 15); // 15 daal dia

    print(head); // o/p: 15 12 10
    return 0;
}