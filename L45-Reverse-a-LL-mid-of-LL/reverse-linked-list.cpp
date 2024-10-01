#include<iostream>
using namespace std;

struct Node{
    public:
        int data;
        Node* head;
        Node* next;
        
        Node(int d){
            this -> data = d;
            this -> next = NULL;    
            this -> head = NULL;
            }
};

// to append elements in Linked List and print 
// method to append elements in a linked list (singly LL)
class LinkedList{
    public:
        Node* head;

        LinkedList(){
            this -> head = NULL;
        }
        void append(int data){
            Node* newNode = new Node(data);
            if(!head){
                head = newNode;
                return;
            }
            Node* lastNode = head;
            while(lastNode -> next){
                lastNode = lastNode -> next;
            }
            lastNode -> next = newNode;
        }

        void print(){
            Node* currNode = head;
            while(currNode){
                cout << currNode -> data << " ";
                currNode = currNode -> next;
            }
            cout<<endl;
        
        }

        void reverseapproach1(){
            Node* prev = NULL;
            Node* curr = head;
            while(curr != NULL){
                Node* forward = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = forward;
            }
            head = prev;
        }

        void reverseApproach2(){
            // reverseLL(head);
        }

        // private:
        // void reverseLL(Node* &curr, Node* prev){

        // }
};


int main(){
    LinkedList list1;
    list1.append(11);
    list1.append(12);
    list1.append(13);
    list1.append(14);
    list1.append(15);

    cout<< "Current Linked List: " << endl;
    list1.print();

    list1.reverseapproach1();
    cout<<"After reverse by approach 1 i.e. by iteration: "<<endl;
    list1.print();

    list1.reverseApproach2();
    cout << "After reverse by approach 2 (recursive): " << endl;
    list1.print();


    
    
    return 0;
}