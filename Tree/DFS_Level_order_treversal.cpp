//DEPTH FIRST SEARCH

#include<iostream>
#include<queue>
using namespace std;
class node{
  public:
  int data;
  node* left;
  node* right;

  node(int d){
    this->data=d;
    this->left=NULL;
    this->right=NULL;
  }
};

node* buildtree(node * root){
  cout<<"  enter data :";
  int data;
  cin>>data;
  root=new node(data);

  if(data==-1){
    return NULL;
  }

  cout<<"enter data for inserting in left of "<<data;
  root->left=buildtree(root->left);
  cout<<"enter data for inserting in right of "<<data;
  root->right=buildtree(root->right);
  return root;
}

void lv_ordertrevarsal(node * root){
   queue<node*> q;
   q.push(root);
   q.push(NULL);    //this is for the "endl" to differentiaite the levels
   while(!q.empty()){
   node *temp=q.front();
   q.pop();
   if(temp==NULL){
    //purana level complete traverse hogya hai
    cout<<endl;
    if(!q.empty()){
      //queue still has child nodes
      q.push(NULL);
    }
   }
   else{
    cout<<temp->data<<" ";
    if(temp->left){   //agar left hai to
      q.push(temp->left);
    }

     if(temp->right){   //agar right hai to
      q.push(temp->right);
    }
   }
   }
}

int main(){
  node * root=NULL;

  //creating  a tree
  root=buildtree(root);
  //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  cout<<"printing DFA traversal "<<endl;
  lv_ordertrevarsal(root);
}