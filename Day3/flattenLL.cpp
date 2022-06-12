#include<bits/stdc++.h>
using namespace std;
class node
    {
    public:
        int data;
        node *next;
        node *child;
        node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

node* merge(node *left, node *right ){
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
node* flattenLL(node* head){

node *left=head;
node *right=head->next;

//flatten both left and right side;

left=flattenLL(left);
right=flattenLL(right);

//merge both the sides

node *ans=merge(left,right);

return ans;



}