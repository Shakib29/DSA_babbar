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

void createmapping(int in[],map<int,int>&nodetoindex,int n){

for(int i=0;i<n;i++){
  nodetoindex[in[i]]=i;
  }}

node *solve (int in[],int pre[],int &index,map<int,int> &nodetoindex,int inorderstart,int inorderend,int n){
  if(index>=n||inorderstart>inorderend){
    return NULL;
  }
  int element=pre[index++];
  node *root=new node(element);
  int position=nodetoindex[element];

  root->left=solve(in,pre,index,nodetoindex,inorderstart,position-1,n);
    root->right=solve(in,pre,index,nodetoindex,position+1,inorderend,n);
    return root;

}

node * create_tree(int in[],int pre[],int n){
  int preorderindex=0;
  map<int ,int> nodetoindex;
  createmapping(in,nodetoindex,n);
  node *ans=solve(in,pre,preorderindex,nodetoindex,0,n-1,n);
  return ans;
}


void printInorder(node* node) {
  if (node == NULL)
    return;
  printInorder(node->left);
  cout << node->data << " ";
  printInorder(node->right);
}
int main()
{
  // Inorder and preorder traversal arrays
  int in[] = {4, 2, 5, 1, 6, 3, 7};
  int pre[] = {1, 2, 4, 5, 3, 6, 7};
  int n = sizeof(in) / sizeof(in[0]);



  // Create the binary tree
  node *root = create_tree(in, pre, n);

  // Print the inorder traversal of the created binary tree
  cout << "Inorder traversal of the created tree: ";
  printInorder(root);
  cout << endl;


   

 
}