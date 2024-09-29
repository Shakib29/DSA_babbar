  
  void inorder(Node* root,vector<int>& arr){
      if(root==NULL){
          return;
      }
      inorder(root->left,arr);
      arr.push_back(root->data);
      inorder(root->right,arr);
  }
  void BSTToMaxHeap(Node* root,vector<int>& arr,int &index){
       if(root==NULL){
            return;
        }
        root->data=arr[index++];
        BSTToMaxHeap(root->left,arr,index);
        BSTToMaxHeap(root->right,arr,index);
  }
    void convertToMaxHeapUtil(Node* root){
        
     vector<int> arr;
    
 int i = 0;
    // inorder traversal to populate 'arr'
    inorder(root, arr);
 
    // BST to MIN HEAP conversion
    BSTToMaxHeap(root, arr, i);
        
    }    