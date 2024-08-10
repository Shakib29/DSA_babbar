#include <iostream>
#include<vector>
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
        //    cout << "Deleting node with data: " << value;
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



void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void InsertAttail(node *&head,node *&tail,int digit){
    node *temp=new node(digit);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }else{
        tail->next=temp;
        tail=temp;

    }
}

node *add(node *&first,node *&second){
    int carry=0;
    node *anshead=NULL;
    node * anstail=NULL;
    while(first!=NULL||second!=NULL||carry!=0){
        int val1=0;
        if(first!=NULL){
        val1=first->data;
        }
        int val2=0;
        if(second!=NULL){
            val2=second->data;
        }
        int sum=carry+val1+val2;
        int digit=sum%10;
        
        InsertAttail(anshead,anstail,digit);
        carry=sum/10;
        if(first!=NULL){
        first=first->next;
        }
        if(second!=NULL){
        second=second->next;
        }
    }
           return anshead;
}

node * reverse(node * &head){
    node * curr=head;
    node * prev=NULL;
    node * forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        curr=prev;
       curr= forward;
    }
    return prev;

}
node *addnum(node *&first,node * &second){
    //1)reverse input list
 first=reverse(first);
 second=reverse(second);
 //2)add both list
 node *ans=add(first,second);
 //3)ans=reverse
 ans=reverse(ans);
  return ans;
}

int main()
{ // creation of new node
    node *node1 = new node(1);
    

    // head pointed to node 1
    node *head = node1;

    // tail pointed to node 1,since now there is only one element
    node *tail = node1;

    InsertAtTail(tail, 0);
    // print(head);
    cout << endl;

    // InsertAtPos(tail, head, 3, 2);
    InsertAtTail(tail,2);
    print(head);

    //second list
    node *node2=new node(3);
    node *head2=node2;
    node *tail2 = node2;
    InsertAtTail(tail2, 5);
    
    // InsertAtTail(tail2, 0);
    
    // InsertAtTail(tail, 1);
    // print(head);

    // cout << endl
    //      << "head->"  << head->data << endl;
    // cout << "tail->" << tail->data << endl;
    //    deletion(head,2);
       cout<<endl;
       print(head2);
       cout<<endl;
   head=add(head,head2);
       print(head);
}
