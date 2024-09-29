
#include <bits/stdc++.h> 
class compare{
    public:
    bool operator()(Node* a,Node* b){
      return a->data>b->data;
    }
};
Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<Node*,vector<Node*>,compare> minheap;

    int k=listArray.size();
    if(k==0){
        return NULL;
    }
    for(int i=0;i<k;i++){
      if(listArray[i]!=NULL){
          minheap.push(listArray[i]);
      }
    }

    Node* head=NULL;
    Node* tail=NULL;

      while(minheap.size()>0){
       Node* top =minheap.top();
       minheap.pop();

       if(top->next!=NULL){
           minheap.push(top->next);
       }

         if(head==NULL){
             head=top;
             tail=top;

         }
         else{
             tail->next=top;
             tail=top;
         }

      }
return head;
}
