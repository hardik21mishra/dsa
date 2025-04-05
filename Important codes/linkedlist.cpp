#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int x) : data(x), next(nullptr) {}
};

void print(Node *head){
    Node *curr = head;
    while(curr){
        cout << curr -> data << " ";
        curr = curr -> next;
    }
    cout << endl;
}

void InsertAtHead(Node* &head, int x){
    Node *newNode = new Node(x);
    if(!head){
        head = newNode;
        return;
    }
    newNode -> next = head;
    head = newNode;
}

void InsertatEnd(Node* &head, int x){
    Node *val = new Node(x);
    if(!head){
        head = val;
        return;
    }
    
    Node* temp = head;
    while(temp -> next){
        temp = temp -> next;
    }

    temp -> next = val;
}

void InsertAtPosition(Node* &head, int pos, int x){
    if(pos < 1){
        cout << "Invalid Position"<< endl;
        return;
    }

    Node* newNode = new Node(x);
    
    if(!head){
        if(pos == 1){
            head = newNode;
        }

        else cout << "Invalid Position" << endl;
    }

    if(pos == 1){
        newNode -> next = head;
        head = newNode;
        return;
    }

    Node* curr = head;

    int i = 1;
    while(curr && i < pos - 1){
        curr = curr -> next;
        i++;
    }

    // If we've reached the end of the list and pos is larger, insert at the end
    if(!curr){
        cout << "Position exceeds length, inserting at the end insted " << endl;
        InsertatEnd(head, x);
        return;
    }

    newNode -> next = curr -> next;
    curr -> next = newNode;
}

void DeleteAtBegin(Node* &head){
    if(!head){
        cout << endl << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    head = head -> next;
    delete temp;
}

void DeleteAtEnd(Node* &head){
    if(!head){
        cout << endl << "List is Empty ";
        return;
    }

    if(!head -> next){
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    while(temp -> next && temp -> next -> next){
        temp = temp -> next;
    }

    Node* tobedeleted = temp -> next;
    temp -> next = nullptr;
    delete tobedeleted;

}

void deleteAtPosition(Node* &head, int pos){
    if(pos < 1){
        cout << "Invalid Position " << endl;
        return;
    }

    if(!head){
        cout << "List is empty" << endl;
        return;
    }

    if(pos == 1){
        DeleteAtBegin(head);
        return;
    }

    Node* curr = head;

    int index = 1;
    
    while(curr && index < pos - 1){
        curr = curr -> next;
        index++;
    }

    if(!curr || !curr -> next){
        cout << "position out of range" << endl;
        return;
    }

    Node* nodetoDelete = curr -> next;
    curr -> next = curr -> next -> next;
    nodetoDelete -> next = nullptr;
    delete nodetoDelete;
}

int listLen(Node* head){
    int s = 0;
    Node* temp = head;

    while(temp){
        temp = temp -> next;
        s++;
    }
    return s;
}

int main(){
    Node* head = nullptr;
    InsertAtHead(head, 10);
    InsertatEnd(head, 20);
    InsertatEnd(head, 30);
    InsertatEnd(head, 40);
    InsertatEnd(head, 50);

    print(head);

    cout << listLen(head);
}