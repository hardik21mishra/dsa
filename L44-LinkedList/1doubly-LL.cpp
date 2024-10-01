#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() {
        cout << "Memory freed for node with data " << data << endl;
    }
};

// Function to print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to insert a new node at the head
void InsertAtHead(Node*& head, Node*& tail, int data) {
    Node* temp = new Node(data);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Function to insert a new node at the tail
void InsertAtTail(Node*& head, Node*& tail, int data) {
    Node* temp = new Node(data);
    if (tail == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// Function to insert a new node at a specific position
void InsertAtPosition(Node*& head, Node*& tail, int position, int data) {
    if (position <= 1) {
        InsertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    // Inserting at the tail if position is out of bounds
    if (temp == NULL) {
        InsertAtTail(head, tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = nodeToInsert;
    } else {
        tail = nodeToInsert; // Update tail if we're inserting at the end
    }
    temp->next = nodeToInsert;
}

// Function to delete a node at a specific position
void DeleteNode(Node*& head, Node*& tail, int position) {
    if (head == NULL) return; // Empty list

    // Deleting the starting node
    if (position == 1) {
        Node* temp = head;
        head = head->next; // Move head to the next node

        if (head != NULL) {
            head->prev = NULL; // Update the new head's prev to NULL
        } else {
            tail = NULL; // If the list is now empty, update tail as well
        }

        delete temp; // Free memory
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;

    // Traverse to find the node to be deleted
    while (cnt < position && curr != NULL) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    // If curr is NULL, the position is out of bounds
    if (curr == NULL) return;

    // Bypass the current node
    prev->next = curr->next;

    if (curr->next != NULL) {
        curr->next->prev = prev; // Update the next node's prev pointer
    } else {
        tail = prev; // If we're deleting the last node, update tail
    }

    delete curr; // Free memory
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtHead(head, tail, 11);
    print(head); // Output: 11

    InsertAtTail(head, tail, 25);
    print(head); // Output: 11 25

    InsertAtPosition(head, tail, 3, 88);
    print(head); // Output: 11 25 88

    InsertAtPosition(head, tail, 4, 89);
    print(head); // Output: 11 25 88 89

    DeleteNode(head, tail, 1); // Delete the first node (11)
    print(head); // Expected output: 25 88 89

    DeleteNode(head, tail, 3); // Delete the last node (89)
    print(head); // Expected output: 25 88

    return 0;
}
