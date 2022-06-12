#include<bits/stdc++.h>
using namespace std;
class node
    {
    public:
        int data;
        node *next;
        node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

node* findMid(node* head){
    node* fast=head;
    node* slow=fast;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

node* merge(node* left , node* right){
    if(left==NULL)
    return right;

    if(right==NULL)
    return left;

    node* ans=new node(-1);
    node* temp=ans;
    while(left!=NULL && right!=NULL){
      

       if(left->data <= right->data) {
        temp->next=left;
        temp=left;
        left=left->next;
       }

        if(right->data <= left->data) {
        temp->next=right;
        temp=right;
        right=right->next;
       }
    }

     while(left!=NULL){
         temp->next=left;
        temp=left;
        left=left->next;
       }

       while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
       }

    return ans;
    
}
node* mergeSort(node* head){
    //find middle element of ll

    node* mid=findMid(head);

    //divide into two halves

    node* left=head;
    node* right=mid->next;
    
    //cut the links btw two
    mid->next=NULL;

    //sort both the sides using recursion
    left=mergeSort(left);
    right=mergeSort(right);

    //merge both the linked list
    node* ans=merge(left,right);

    return ans;

}