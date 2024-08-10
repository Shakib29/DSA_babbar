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

bool isbst(node *root,int min,int max){
  if(root==NULL)
  return true;

  if(root->data>min&&root->data<max){
    bool left=isbst(root,min,root->data);
    bool right=isbst(root,root->data,max);
    return left && right;
  }
  return false;
}

bool check_bst(node *root){
  return isbst(root,INT32_MIN,INT32_MAX);
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

    // Checking if the tree is a BST
    if (check_bst(root)) {
        cout << "The tree is a BST." << endl;
    } else {
        cout << "The tree is not a BST." << endl;
    }

    return 0;
    
 
} 