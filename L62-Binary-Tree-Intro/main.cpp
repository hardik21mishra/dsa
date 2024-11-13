#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1) return NULL;

    cout << "Enter data at left of : " <<data << endl;
    root -> left = buildTree(root -> left);
    
    cout << "Enter data at right of : " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void level_Order_Traversal(node* root){
    queue <node*> q;
    q.push(root);
    q.push(NULL); // using NULL as a separator between different levels of the tree

    while (!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //matlab purana level traverse ho chuka hai
            cout << endl;
            if(!q.empty()){
                // queue still has child nodes
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
    
}

// prints in single line
void reversal_level_order_traversal_single_line(node* root){
    if (!root) return;
    queue <node*> que;
    stack <int> s;

    que.push(root);

    while(!que.empty()){
        node* temp = que.front();
        que.pop();

        s.push(temp -> data);

        if(temp -> left) que.push(temp -> left);
        if(temp -> right) que.push(temp -> right);
    }

    cout << "Reversal level order traversal: "<<endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// // following will print tree in reverse in multiple lines 
void reversal_level_order_traversal_multiple_lines(node* root){
    if (!root) return;
    queue <node*> qu;
    vector<vector<int>> levels;
    qu.push(root);

    while(!qu.empty()){
        int level_size = qu.size();
        vector <int> current_level;

        // process all nodes at current level
        for(int i = 0 ; i < level_size ; ++i){
            node* temp = qu.front();
            qu.pop();
            
            // store the current node data
            current_level.push_back(temp -> data);

            // push left and right children
            if (temp->left) {
                qu.push(temp->left);
            }
            if (temp->right) {
                qu.push(temp->right);
            }
        }
        // After processing all nodes at the current level, store the level
        levels.push_back(current_level);
    }
    // Print the levels in reverse order
    cout << "Reverse Level Order Traversal: " << endl;
    for (int i = levels.size() - 1; i >= 0; --i) {
        for (int j = 0; j < levels[i].size(); ++j) {
            cout << levels[i][j] << " ";
        }
        cout << endl; // Print each level on a new line
    }
} 

int main(){
    node* root = NULL;

    //creating a tree
    root = buildTree(root);

    // sample tree : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //level order
    cout << "Printing the tree level order traversal way" << endl;
    level_Order_Traversal(root);

    return 0;
}