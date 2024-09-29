
class trienode {
public:
    char data;
    trienode* children[26];
    int count;
    bool isterminal;

    trienode(char ch) : data(ch), isterminal(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        count=0;
        isterminal=false;
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

        int index = word[0] - 'a';
        trienode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new trienode(word[0]);
            root->count++;
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

        int index = word[0] - 'a';
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

        int index = word[depth] - 'a';
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

    void lcp(string str,string &ans){
        //first string ka loop ton traverse each character
        for(int i=0;i<str.length();i++){
            char ch=str[i];

            if(root->count==1){
                ans.push_back(ch);
                //aage badh jao
                int index=ch-'a';
                root=root->children[index];
            }else{
                break;
            }

            if(root->isterminal){
                break;
            }
        }
    }

  void print_suggesstions(trienode* curr, vector<string>& temp, string& prefix) {
    if (curr->isterminal) {
        temp.push_back(prefix); // Add the current prefix to the suggestions list
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        trienode* next = curr->children[ch - 'a'];

        if (next != NULL) {
            prefix.push_back(ch); // Add the character to the current prefix
            print_suggesstions(next, temp, prefix); // Recursively get suggestions
            prefix.pop_back(); // Remove the character after recursion
        }
    }
}



    vector<vector<string>> getsuggesstion(string str){
        trienode* prev=root;
        vector<vector<string>> output;
        string prefix="";

        for(int i=0;i<str.length();i++){
            char lastch=str[i];

            prefix.push_back(lastch);

            //check for match
         trienode * curr=prev->children[lastch-'a'];

         //if not  found
         if(curr==NULL){
             break;
         }

         //if found
         vector<string> temp;
         print_suggesstions(curr,temp,prefix);

         output.push_back(temp);
         temp.clear();
        prev=curr;
        }
        return output;
    }
};





vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
   trie  * t=new trie();
   for(int i=0;i<contactList.size();i++){
       string str=contactList[i];
       t->insertword(str);
   }
   return t->getsuggesstion(queryStr);
}