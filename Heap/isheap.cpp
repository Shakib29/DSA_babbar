//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
  
  int nodecounter(struct Node* tree){
      if(tree==NULL){
          return 0;
      }
      int ans=1+nodecounter(tree->left)+nodecounter(tree->right);
      return ans;
  }
  
  bool iscbt(struct Node* tree,int index,int nodecount){
      if(tree==NULL){
          return true;
      }
      if(index>=nodecount){   //this is cbt main condn
          return false;
      }
      else{
          bool leftans=iscbt(tree->left,2*index+1,nodecount);
           bool rightans=iscbt(tree->right,2*index+2,nodecount);
           return (leftans&&rightans);
      }
  }
  bool maxorder(struct Node* tree){
      //leaf node
      if(tree->left==NULL&&tree->right==NULL){
          return true;
      }
      if(tree->right==NULL){
          return(tree->data>tree->left->data);
      }else{
          bool left=maxorder(tree->left);
          bool right=maxorder(tree->right);
          return(left&&right&&(tree->data>tree->right->data&&tree->data>tree->left->data));
      }
  }
  
    bool isHeap(struct Node* tree) {
        int index=0;
        int nodecount=nodecounter(tree);
        if(iscbt(tree,index,nodecount)&&maxorder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};
