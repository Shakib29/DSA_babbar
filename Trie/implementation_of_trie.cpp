#include <iostream>
#include <string>
using namespace std;

class trienode {
public:
    char data;
    trienode* children[26];
    bool isterminal;

    trienode(char ch) : data(ch), isterminal(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class trie {
public:
    trienode* root;

    trie() {
        root = new trienode('\0');
    }

    ~trie() {
        deleteTrie(root);
    }

    void deleteTrie(trienode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL) {
                deleteTrie(node->children[i]);
            }
        }
        delete node;
    }

    void insertutil(trienode* root, string word) {
        if (word.length() == 0) {
            root->isterminal = true;
            return;
        }

        int index = word[0] - 'A';
        trienode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new trienode(word[0]);
            root->children[index] = child;
        }

        insertutil(child, word.substr(1));
    }

    void insertword(string word) {
        insertutil(root, word);
    }

    bool searchutil(trienode* root, string word) {
        if (word.length() == 0) {
            return root->isterminal;
        }

        int index = word[0] - 'A';
        trienode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return searchutil(child, word.substr(1));
    }

    bool searchword(string word) {
        return searchutil(root, word);
    }

    bool deleteutil(trienode* root, string word, int depth) {
        if (root == NULL) return false;

        if (depth == word.size()) {
            // If the word is the end of a valid word
            if (root->isterminal) {
                root->isterminal = false;
                // If root has no children, we can delete this node
                return isEmpty(root);
            }
            return false;
        }

        int index = word[depth] - 'A';
        trienode* child = root->children[index];
        
        if (deleteutil(child, word, depth + 1)) {
            // If true is returned then delete the mapping of character and NULL it
            root->children[index] = NULL;
            // Return true if root does not have any children and is not a terminal node
            return (!root->isterminal && isEmpty(root));
        }
        return false;
    }

    void deleteword(string word) {
        if (!word.empty()) {
            deleteutil(root, word, 0);
        }
    }

    bool isEmpty(trienode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    trie* t = new trie();
    t->insertword("ABCD");
    cout << "The word 'ABCD' is ";
    if (t->searchword("ABCD")) {
        cout << "present" << endl;
    } else {
        cout << "not present" << endl;
    }

    t->deleteword("ABCD");
    cout << "After deletion, the word 'ABCD' is ";
    if (t->searchword("ABCD")) {
        cout << "present" << endl;
    } else {
        cout << "not present" << endl;
    }

    delete t; // Free allocated memory
    return 0;
}
