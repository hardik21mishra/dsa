// L81
// gfg hard question
// direct gfg code, not meant to be run here in vs code 
// therefore ignore all errors

// implement a phone directory


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
            int index = tolower(word[0]) - 'a';
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
        
        void printSugg(TrieNode* curr, vector<string> &temp, string prefixStr){
            if(curr -> isTerminal) temp.push_back(prefixStr);
            
            for(char ch = 'a' ; ch <= 'z' ; ch++){
                TrieNode* next = curr -> children[ch - 'a'];
                
                if(next){
                    prefixStr.push_back(ch);
                    printSugg(next, temp, prefixStr);
                    prefixStr.pop_back();                }
            }
        }
        
        // get suggestions function
        vector<vector<string>> getSugg(string qStr){
            TrieNode* prev = root;
            vector<vector<string>> output;
            string prefixStr = "";
            
            for(int i = 0 ; i < qStr.length() ; i++){
                char lastch = tolower(qStr[i]);
                prefixStr.push_back(lastch);
                
                // check if last char exists
                TrieNode* curr = prev -> children[lastch - 'a'];
                //if not found
                if(!curr){
                    for (int j = i; j < qStr.length(); j++) {
                    output.push_back({"0"});
                    }
                    break;
                } // if condition ends
                
                // if found
                vector<string> temp;
                printSugg(curr, temp, prefixStr);
                output.push_back(temp);

                prev = curr;
            } // for loop ends
            return output;
        }
        
};





class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie* t = new Trie();
        for(int i = 0 ; i < n ; i++){
            string str = contact[i];
            t -> insertWord(str);
        }
        
        return t -> getSugg(s);
    }
};