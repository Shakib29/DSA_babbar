#include <iostream>
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

bool identical(node *r1,node *r2){
  //base case
  if(r1==NULL&&r2==NULL){
    return true;
  }
  if(r1!=NULL&&r2==NULL){
    return false;
  }
  if(r1==NULL&&r2!=NULL){
    return false;
  }
  bool left=identical(r1->left,r2->left);
  bool right=identical(r1->right,r2->right);

  bool value=r1->data==r2->data;

  if(left&&right&&value){
    return true;
  }
  else{
    return false;
  }

}

int main()
{
   // Creating first tree
  node* root1 = new node(1);
  root1->left = new node(2);
  root1->right = new node(3);
  root1->left->left = new node(4);
  root1->left->right = new node(5);

  // Creating second tree
  node* root2 = new node(1);
  root2->left = new node(2);
  root2->right = new node(3);
  root2->left->left = new node(4);
  root2->left->right = new node(5);

  // Checking if trees are identical
  if (identical(root1, root2)) {
    cout << "The trees are identical." << endl;
  } else {
    cout << "The trees are not identical." << endl;
  }
   
  return 0;
}