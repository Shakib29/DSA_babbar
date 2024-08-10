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

void solve(node *root,int sum,int &maxsum,int len,int &maxlen){
  if(root==NULL){
   if(len>maxlen){
    maxlen=len;
     maxsum=sum;
   }else if(len==maxlen){
    maxsum=max(sum,maxsum);
   }
   return;
  }
  sum=sum+root->data;


  solve(root->left,sum,maxsum,len+1,maxlen);
     solve(root->right,sum,maxsum,len+1,maxlen);

}
int fins_lon_sum(node *root){
int len=0;
int sum=0;
int maxlen=0;
int maxsum=0;
solve(root,sum,maxsum,len,maxlen);
return maxsum;
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
   cout<< fins_lon_sum(root);

   

 
}