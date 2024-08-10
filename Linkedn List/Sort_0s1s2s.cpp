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

//Approach 1
// node * sort(node *&head){
// int countone=0;
// int counttwo=0;
// int countzero=0;
// node* temp=head;
// while(temp!=NULL){
//     if(temp->data==0){
//         countzero++;
//     }else if(temp->data==1){
//         countone++;
//     }else if(temp->data==2){
//         counttwo++;
//     }
//     temp=temp->next;
// }
// temp=head;
// while (temp!=NULL){
//    if(countzero!=0){
//     temp->data=0;
//     countzero--;
//    }else if(countone!=0){
//      temp->data=1;
//     countone--;
//    }else if(counttwo!=0){
//      temp->data=2;
//     counttwo--;
//    }
//   temp=temp->next;
// }
// return head;
// }

//Approach 2

void insertingnodeattail(node *&tail,node * curr){
    tail->next=curr;
    tail=curr;
    
}

node *sort(node *&head){
    if (head == nullptr || head->next == nullptr)
        return head;

node *onehead=new node(-1);
node *onetail=onehead;
node *twohead=new node(-1);
node *twotail=twohead;
node *zerohead=new node(-1);
node *zerotail=zerohead;
node *curr=head;
//craete separate list of 0 and 1 and 2
while(curr!=NULL){
    int value=curr->data;
    if(value==0){
        insertingnodeattail(zerotail,curr);
    }else  if(value==1){
        insertingnodeattail(onetail,curr);
    }else  if(value==2){
        insertingnodeattail(twotail,curr);
    }
    curr=curr->next;
}
//merge three list
if(onehead->next!=NULL){
    zerotail->next=onehead->next;                //1s list is not empty
}else{
     zerotail->next=twohead->next;                 //1s list is empty
}
onetail->next=twohead->next;
twotail->next=NULL;

//setup head
head=zerohead->next;
//delete dummy node;
delete zerohead;
delete onehead;
delete twohead;

return head;
}


int main()
{ // creation of new node
    node *node1 = new node(1);
    

    // head pointed to node 1
    node *head = node1;

    // tail pointed to node 1                ,since now there is only one element
    node *tail = node1;

    InsertAtTail(tail, 0);
    // print(head);
    cout << endl;

    // InsertAtPos(tail, head, 3, 2);
    InsertAtTail(tail,2);
    InsertAtTail(tail, 0);
    
    InsertAtTail(tail, 1);
    
    InsertAtTail(tail, 2);
    // print(head);

    // cout << endl
    //      << "head->" << head->data << endl;
    // cout << "tail->" << tail->data << endl;
    //    deletion(head,2);
       cout<<endl;
       print(head);
    //    tail->next=head->next;
       
      head=sort(head);
      cout<<endl<<"sorting 0's and 1's and 2's"<<endl;
      print(head);
}
