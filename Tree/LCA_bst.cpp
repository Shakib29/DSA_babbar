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

node * lca(node *root,node*a,node *b){
  if(root==NULL){
    return NULL;
  }
   while(root!=NULL){
  if(root->data<a->data&&root->data<b->data){
    root=root->right;
  }
   else if(root->data>a->data&&root->data>b->data){
     root=root->left;
  }
 
 return root;
}
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



       node *temp=lca(root,root->left,root->right);
       cout<<temp->data;
    return 0;
    
 
} 