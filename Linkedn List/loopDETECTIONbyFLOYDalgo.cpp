//floyd detection of cycles
//aur last function hai "starting node "find karne ka function

#include <iostream>
#include<map>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data) // constructor
    {
        this->data = data;
        this->next = NULL;
    }

    ~node(){                     //destructor
        int value=this->data;
          //Free Memory
          if(this->next!=NULL){
            delete next;
            this->next=NULL;
          }
           cout << "Deleting node with data: " << value;
        }
};

void InsertAtHead(node *&head, int d)     //insert at beginning
{
    node *temp = new node(d); // creation of new node
    temp->next = head;
    head = temp;
}

void InsertAtTail(node *&tail, int d)
{
    node *temp = new node(d); // creation of new node
    tail->next = temp;
    tail = tail->next;
}

void InsertAtPos(node *&tail, node *&head, int pos, int d)
{
    if (pos == 1)
    {
        InsertAtHead(head, d);
        return;
    }
    node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // inserting at end
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    node *newnode = new node(d); // creation of new node
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletion(node *&head,int pos){
   //deletion at the beginning
   if(pos==1){
    node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;                 //free memory node
   }else{
    // deleting node in middle or last
    node *curr=head;
    node *prev=NULL;
    int cnt=1;
    while(cnt <pos){
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;

   }


}

node* loopdetect(node *head){
    if(head==NULL){
        return NULL;
    }
 node *slow=head;
 node * fast =head;
while(slow!=NULL&&fast!=NULL){
   
    fast=fast->next;
    if(fast!=NULL){
        fast=fast->next;
    }

    slow=slow->next;

if(slow==fast){
    // cout<<"  present at =>  "<<slow->data;
    return slow;
}
}
return NULL;
}


void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
//to get starting node of cycle

node *getstartingnode(node *&head){
    if(head==NULL){
        return NULL;
    }
    node*intersection=loopdetect(head);
    if(intersection ==NULL){
        return NULL;
    }
    node *slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;

}
//remove loop
node *removeloop(node*&head){
    if(head==NULL){
        return NULL;
    }
    node*startingnode=getstartingnode(head);
    if(startingnode==NULL){
        return head;
    }
    node*temp=startingnode;
    while(temp->next!=startingnode){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}

int main()
{ // creation of new node
    node *node1 = new node(5);
    

    // head pointed to node 1
    node *head = node1;

    // tail pointed to node 1                ,since now there is only one element
    node *tail = node1;

    InsertAtTail(tail, 12);
    print(head);
    cout << endl;

    InsertAtPos(tail, head, 3, 9);
    InsertAtPos(tail, head, 4, 13);
    InsertAtPos(tail, head,5, 19);
    print(head);

    cout << endl
         << "head->" << head->data << endl;
    cout << "tail->" << tail->data << endl;
    //    deletion(head,2);
       cout<<endl;
       print(head);
       tail->next=head->next;
    //   if (loopdetect(head))
    // {
    //     cout <<  " has a cycle";
    // }
    // else
    // {
    //     cout << "not have a cycle";
    // } 
   node*result= getstartingnode(head);     
   cout<<endl<<"starting node of loop is :"<<result->data;

   head=removeloop(head);
   
}
