
// note that i have only coded a small part of video
// revisit to code complete






#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {};
};

void levelOrderTraversal(Node* root) {
    if (root == NULL) return; // Base case: if the tree is empty

    // Create a queue to store nodes at each level
    queue<Node*> q;
    q.push(root); // Start with the root node

    // Loop until the queue is empty
    while (!q.empty()) {
        // Get the front node from the queue
        Node* current = q.front();
        q.pop();

        // Print the value of the current node
        cout << current->data << " ";

        // Enqueue the left child if it exists
        if (current->left != NULL) q.push(current->left);

        // Enqueue the right child if it exists
        if (current->right != NULL) q.push(current->right);
    }
}


Node* insertIntoBST(Node* &root, int d){
    if(!root){
        root = new Node(d);
        return root;
    }

    if(d > root -> data){
        // right part me insert karna hai
        root -> right = insertIntoBST(root -> right, d);
    }
    else{
        // left part insert karna hai
        root -> left = insertIntoBST(root -> left, d);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        insertIntoBST(root, data);
        cin >> data;
    }
}
int main(){
    Node* root = NULL;

    cout << "Enter data to create BST " << endl;
    takeInput(root);

    cout << "Printing  the BST " << endl;
    levelOrderTraversal(root);
    return 0;
}