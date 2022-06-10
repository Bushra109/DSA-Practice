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

void insertTail( Node* &tail, Node* curr){
tail->next=curr;
tail=curr;
}
Node* SortList(Node* head){
Node* zerohead=new Node(-1);
Node* zerotail=zerohead;
Node* onehead=new Node(-1);
Node* onetail=onehead;
Node* twohead=new Node(-1);
Node* twotail=twohead;

Node* curr=head;


//creating individual 0s 1s 2s list
while(curr != NULL){
    int val=curr->data;

    if(val==0){
        insertTail(zerotail,curr);
       
    }
     if(val==1){
        insertTail(onetail,curr);
       
    }
     if(val==2){
        insertTail(twotail,curr);
       
    }


     curr=curr->next;

}

//merging all the list

//1s list is not empty
if(onehead->next!=NULL){
    zerotail->next=onehead->next;
}
else{
    zerotail->next=twohead->next;
}

//meging list in normal condition
onetail->next=twohead->next;
twotail->next=NULL;

//setup head
head=zerohead->next;

//delete dummy node
delete zerohead;
delete onehead;
delete twohead;

return head;

}