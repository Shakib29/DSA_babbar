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

node * solve(vector<int> &preorder,int min,int max,int &i){
if(i>=preorder.size()){
  return NULL;
}
if(preorder[i]<min||preorder[i]>max){
  return NULL;
}
node * root=new node(preorder[i++]);
root->left=solve(preorder,min,root->data,i);
root->left=solve(preorder,root->data,max,i);
return root;

}

node * pretobst(vector<int> preorder){
  int min=INT32_MIN;
  int max=INT32_MAX;
  int i=0;
return solve(preorder,min,max,i);

}

void print_bst(node* root) {
    if (root == NULL) {
        return;
    }
    // Print the left subtree
    print_bst(root->left);
    // Print the current node
    cout << root->data << " -> ";
    // Print the right subtree
    print_bst(root->right);
    }
int main()
{
vector<int> preorder = {10, 5, 2, 8, 20, 15, 30};
      node* bst_root = pretobst(preorder);
    
    print_bst(bst_root);
   
    
 
} 