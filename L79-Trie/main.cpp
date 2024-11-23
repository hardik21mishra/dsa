#include <iostream>
#include <string>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            this -> data = ch;
            for(int i = 0 ; i < 26 ; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word){
            // base case
            if(word.length() == 0){
                root -> isTerminal = true;
                return;
            }

            // assuming string word is in CAPS
            int index = word[0] - 'A';
            TrieNode* child;

            //present
            if(root -> children[index]){
                // aage badh jao
                child = root -> children[index];
            }
            else{ // absent
                child = new TrieNode(word[0]);
                root -> children[index] = child;
            }

            // ek case hamne kar diya 
            // baaki recursion sambhal lega
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word){
            insertUtil(root, word);
        }


        // SEARCHING OPERATIONS FUNCTIONS
        
        bool searchUtil(TrieNode* root, string word){
            // base case
            if(word.length() == 0){
                return root -> isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            //present
            if(root -> children[index]){
                child = root -> children[index];
            }
            else{
                return false;
            }

            return searchUtil(child, word.substr(1));
        }

        bool searchWord(string word){
            return searchUtil(root, word);
        }
};
int main(){
    cout << "fvjhbhjhj" << endl;
    
    Trie* t = new Trie();
    t -> insertWord("ABCD");

    cout << "Present ? " << (t->searchWord("ABC") ? "Yes" : "No") << endl;
    return 0;
}