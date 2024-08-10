#include <iostream>
#include <vector>
#include <queue>

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
vector<int> zigzga(node * root){
  vector<int> result;
   if(root==NULL){
    return result;
   }
   queue<node *> q;
   bool lefttoright=true;
   q.push(root);

   while(!q.empty()){
     int size=q.size();
     vector<int> ans(size);
     //level process
     for(int i=0;i<size;i++){
      node* frontnode=q.front();
      q.pop();
        //normal insert or reverse insert
      int index=lefttoright?i:size-i-1;
      ans[index]=frontnode->data;

      if(frontnode->left){
       q.push(frontnode->left);
      }
       if(frontnode->right){
       q.push(frontnode->right);
      }
     }
      //direction change
      lefttoright=!lefttoright;
      for(auto i:ans){
        result.push_back(i);
      
     }
   }
return result;
   

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
   vector<int> result = zigzga(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

 
}