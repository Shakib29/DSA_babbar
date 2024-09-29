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


void inorder(node *root,vector<int> &in){
  //base case
  if(root==NULL){
    return;
  }
  inorder(root->left,in);
  in.push_back(root->data);
  inorder(root->right,in);
}

node * inordertobst(int s,int e,vector<int> in){
  if(s>e)
  return NULL;

  int mid=(s+e)/2;
  node* root=new node(in[mid]);
  root->left=inordertobst(s,mid-1,in);
      root->right=inordertobst(mid+1,e,in);
  return root;
}

node* balancedbst(node* root){
 vector<int> in;
 inorder(root,in);

 return inordertobst(0,in.size()-1,in);

}



void print_balanced_bst(node* root) {
    while (root != NULL) {
        cout << root->data << " -> ";
        root = root->right;
    }
    cout << "NULL" << endl;
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

     

      
    
    node* flattened_bst = balancedbst(root);
    print_balanced_bst(flattened_bst);

    
    

    return 0;
    
 
} 