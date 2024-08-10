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

node * lca(node *root,int n1,int n2){
  if(root==NULL){
    return NULL;
  }
  if(root->data==n1||root->data==n2){
     return root;
  }
  node *leftans=lca(root->left,n1,n2);
    node *rightans=lca(root->right,n1,n2);
      
      if  (leftans!=NULL&&rightans!=NULL){
      return root;  
    }else if (leftans!=NULL&&rightans==NULL){
      return leftans;
    }else if  (leftans==NULL&&rightans!=NULL){
      return rightans;
    }else{
      return NULL;
    }
    
}

int main()
{
  // Create a sample binary tree
  node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);
 node *ans = lca(root, 4, 5);

  if (ans != NULL) {
    cout << "LCA of 4 and 5 is: " << ans->data << endl;
  } else {
    cout << "No LCA found." << endl;
  }

   

 
}