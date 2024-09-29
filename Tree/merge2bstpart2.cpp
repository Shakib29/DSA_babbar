#include<iostream>
using namespace std;

class node {
public:
  int data;
  node *left;
  node *right;

  node(int d) {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

// Convert BST to a sorted Doubly Linked List (DLL)
void convertto_sorted_DLL(node *root, node *&head) {
  if(root == NULL) {
    return;
  }

  convertto_sorted_DLL(root->left, head);

  root->right = head;
  if(head != NULL) {
    head->left = root;
  }
  head = root;

  convertto_sorted_DLL(root->right, head);
}

// Merge two sorted Doubly Linked Lists
node* mergetwolist(node *head1, node *head2) {
  node *head = NULL;
  node *tail = NULL;
  
  while(head1 != NULL && head2 != NULL) {
    if(head1->data < head2->data) {
      if(head == NULL) {
        head = head1;
        tail = head1;
        head1 = head1->right;
      } else {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
      }
    } else {
      if(head == NULL) {
        head = head2;
        tail = head2;
        head2 = head2->right;
      } else {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
      }
    }
  }
  
  while(head1 != NULL) {
    tail->right = head1;
    head1->left = tail;
    tail = head1;
    head1 = head1->right;
  }

  while(head2 != NULL) {
    tail->right = head2;
    head2->left = tail;
    tail = head2;
    head2 = head2->right;
  }
  
  return head;
}

// Count the number of nodes in a Doubly Linked List
int count(node *head) {
  int n = 0;
  node *temp = head;
  while(temp != NULL) {
    n++;
    temp = temp->right;
  }
  return n;
}

// Convert sorted Doubly Linked List to Balanced BST
node* sortedLLtoBST(node *&head, int n) {
  if(n <= 0 || head == NULL) {
    return NULL;
  }

  node* leftpart = sortedLLtoBST(head, n/2);
  
  node *root = head;
  root->left = leftpart;

  head = head->right;

  root->right = sortedLLtoBST(head, n - n/2 - 1);
  return root;
}

// Main function to merge two BSTs and return a balanced BST
node* sorted(node* root1, node* root2) {
  node* head1 = NULL;
  convertto_sorted_DLL(root1, head1);
  if(head1 != NULL) {
    head1->left = NULL;
  }

  node* head2 = NULL;
  convertto_sorted_DLL(root2, head2);
  if(head2 != NULL) {
    head2->left = NULL;
  }

  // Merge two sorted lists
  node* head = mergetwolist(head1, head2);

  // Convert sorted DLL to BST
  return sortedLLtoBST(head, count(head));
}
