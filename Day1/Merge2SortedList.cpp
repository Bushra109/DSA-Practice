#include<stdio.h>
class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

Node* solve(Node* first, Node* second){
    Node* curr1=first;
    Node* next1=curr1->next;
    Node* curr2=second;
    Node* next2=curr2->next;

    //if only 1 element is present in linked list
    if(first->next==NULL){
        first->next=second;
        return first;
    }

    while(curr2!=NULL && next1!=NULL){
        if((curr2->data==curr1->data)&&(curr2->data<=next1->data)){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;


            curr1=curr2;
            curr2=next2;
        }
        else{
            curr1=next1;
            next1=next1->next;
        }
    }
    return first;

}

Node* Merge2SortedList(Node* first, Node* second){
    if(first==NULL)
    return second;
    if(second==NULL)
    return first;

    //comparing the first value of both list
    if(first->data<=second->data){
       return solve(first, second);
    }
    else{
       return solve(second, first);
    }
}