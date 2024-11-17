#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *left, *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {};
};

void morrisInorderTraversal(TreeNode* root){
    TreeNode* curr = root;

    while(curr){
        if(!curr -> left){
            // If there is no left subtree, visit the node
            cout << curr -> data << " ";
            // Move to the right subtree
            curr = curr -> right;
        }
        else{
             // Find the inorder predecessor of the current node
            TreeNode* pred = curr -> left;
            while(pred -> right && pred -> right != curr){
                pred = pred -> right;
            }

            // If the predecessor's right is NULL, set it to the current node (threading)
            if(!pred -> right){
                pred -> right = curr;
                curr = curr -> left;
            }
            // If the thread already exists, remove it and visit the current node
            else{
                pred -> right = NULL;  // Remove the thread
                cout << curr -> data << " ";
                curr = curr -> right;
            }
        }
    }
}


int main(){
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);

    cout << "Morris Inorder Traversal: ";
    morrisInorderTraversal(root);
    cout << endl;

    return 0;
}