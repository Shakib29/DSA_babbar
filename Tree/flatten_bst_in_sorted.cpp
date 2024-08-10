#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
class node
{
public:
  int data;
  node *left;
  node *right;

  node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};


void inorder(node *root,vector<node*> &in){
  //base case
  if(root==NULL){
    return;
  }
  inorder(root->left,in);
  in.push_back(root);
  inorder(root->right,in);
}

vector<node*> flatten_bst(node * root){
  vector<node*> in;
  inorder(root,in);
  int i=0;
for(int i=0;i<in.size()-1;i++){
    in[i]->left=NULL;
    in[i]->right=in[i+1];
}
   
    // The last node's right pointer should be NULL
    in[in.size()-1]->left = NULL;
    in[in.size()-1]->right = NULL;

    return in;
}
int main()
{
   node* root = new node(10);
    root->left = new node(5);
    root->right = new node(20);
    root->left->left = new node(2);
    root->left->right = new node(8);
    root->right->left = new node(15);
    root->right->right = new node(30);

     
  vector<node*> flattened_bst = flatten_bst(root);
      
    // Print the flattened BST
    node* current = flattened_bst[0];
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->right;
    }
    cout << "NULL" << endl;

    return 0;
    
 
} 