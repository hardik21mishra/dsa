// code with a driver function included so that it can 
// be directly run in VS Code or any other C++ compiler.
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        this->data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index]) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void printSugg(TrieNode* curr, vector<string>& temp, string prefixStr) {

        if (curr->isTerminal) {
            temp.push_back(prefixStr);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];
            if (next) {
                prefixStr.push_back(ch);
                printSugg(next, temp, prefixStr);
                prefixStr.pop_back();
            }
        }
    }

    vector<vector<string>> getSugg(string qStr) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefixStr = "";

        for (int i = 0; i < qStr.length(); i++) {
            char lastch = qStr[i];
            prefixStr.push_back(lastch);

            TrieNode* curr = prev->children[lastch - 'a'];
            if (!curr) {
                for (int j = i; j < qStr.length(); j++) {
                    output.push_back({"0"});
                }
                break;
            }

            vector<string> temp;
            printSugg(curr, temp, prefixStr);
            output.push_back(temp);
            prev = curr;
        }

        return output;
    }
};

int main() {
    int n;
    cout << "Enter the number of contacts: ";
    cin >> n;

    string contact[n];
    cout << "Enter the contacts:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> contact[i];
    }

    string s;
    cout << "Enter the query string: ";
    cin >> s;

    // Create a Trie
    Trie* t = new Trie();

    // Insert contacts into the Trie
    for (int i = 0; i < n; i++) {
        t->insertWord(contact[i]);
    }

    // Get suggestions for the query string
    vector<vector<string>> result = t->getSugg(s);

    // Print results
    cout << "\nSuggestions for each prefix of \"" << s << "\":" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Prefix: " << s.substr(0, i + 1) << " -> ";
        if (result[i].size() == 1 && result[i][0] == "0") {
            cout << "No suggestions";
        } else {
            for (string str : result[i]) {
                cout << str << " ";
            }
        }
        cout << endl;
    }

    delete t; // Clean up dynamically allocated memory
    return 0;
}
