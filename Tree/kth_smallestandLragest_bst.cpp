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

  if(root->data>=min&&root->data<=max){
    bool left=isbst(root,min,root->data);
    bool right=isbst(root,root->data,max);
    return left && right;
  }else{
  return false;
}
}

int solve(node *root,int &i,int k){
if(root==NULL){
return -1;
}
//L
int left=solve(root->left,i,k);
if(left!=-1){
  return left;
}
//N
i++;
if(i==k){
  return root->data;
}

//R
return solve(root->right,i,k);
}

int kth_smallest_bst(node *root,int k){
  int i=0;
  int ans=solve(root,i,k);
  return ans;
}

// Helper function to find the k-th maximum element
int solve_max(node* root, int& i, int k) {
    if (root == NULL) {
        return -1;
    }

    // R (reverse in-order)
    int right = solve_max(root->right, i, k);
    if (right != -1) {
        return right;
    }

    // N
    i++;
    if (i == k) {
        return root->data;
    }

    // L
    return solve_max(root->left, i, k);
}

// Function to find the k-th maximum element in BST
int kth_maximum_bst(node* root, int k) {
    int i = 0;
    int ans = solve_max(root, i, k);
    return ans;
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

    cout<<kth_smallest_bst(root,3)<<endl;
    cout<<kth_maximum_bst(root,3);
    return 0;
    
 
} 