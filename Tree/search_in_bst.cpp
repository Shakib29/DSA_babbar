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

node * insertintobst(node *root,int data){
  //base case
  if(root==NULL){
    return new node(data);
  
  }

  if(data>root->data){
    root->right=insertintobst(root->right,data);
  }else{
        root->left=insertintobst(root->left,data);

  }
  return root;
}

void takeinput(node * &root){
  int data;
  cin>> data;
  while(data!=-1){
    root=insertintobst(root,data);
    cin>>data;
  }
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


// bool searchelement(node*root,int x){
//   if(root==NULL){
//     return false;
//   }
//   if(root->data==x){
//     return true;
//   }

//   if(root->data>x){
//     return searchelement(root->left,x);
//   }else{
//     return searchelement(root->right,x);
//   }

// }


bool searchelement(node *root,int x){
  node * temp=root;
  while(temp!=NULL){
if(temp->data==x){
  return true;
}
if(temp->data>x){
  searchelement(root->left,x);
}else{
  searchelement(root->right,x);
}

  }
  return false;
}

int main()
{
  node *root = NULL;
    cout << "Enter elements for the BST (-1 to stop): " << endl;
    takeinput(root);

    // cout << "Level-order traversal of the BST: " << endl;
    // levelOrderTraversal(root);

    int x;
    cout << "Enter the element to search: ";
    cin >> x;

    if (searchelement(root, x)) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
 
} 