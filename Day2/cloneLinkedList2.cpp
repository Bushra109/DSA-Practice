#include<stdio.h>

using namespace std;
class Node
    {
    public:
        int data;
        Node *next;
        Node *random;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
Node* insertTail(Node* &head, Node* &tail, int val){
    Node* temp=new Node(val);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}
Node* cloneLL2(Node* head){

    //Step1.create a clone list
    Node* clonehead=NULL;
    Node* clonetail=NULL;

    //copy the contents of original ll to clone ll

    Node* temp=head;
    while(temp!=NULL){
        insertTail(clonehead,clonetail,temp->data);
        temp=temp->next;
    }

    //Step2. adding clone nodes in btw original node

    Node* originalnode=head;
    Node* clonenode=clonehead;

    while(originalnode!=NULL && clonenode!=NULL){

        //changing links of original node

        Node* next=originalnode->next;
        originalnode->next=clonenode;
        originalnode=next;

        //changing links of clone node

        next=clonenode->next;
        clonenode->next=originalnode;
        clonenode=next;
    }

    //step3. Copying random pointer
    originalnode=head;
    clonenode=clonehead;

    while(originalnode!=NULL && clonenode!=NULL){

        if(originalnode->random!=NULL){
        clonenode->random=originalnode->random->next;
        }
        else{
            clonenode->random=NULL;
        }

        clonenode=clonenode->next;
        originalnode=originalnode->next;

    }

    //step4. Revert back changes done in step 2
    originalnode=head;
    clonenode=clonehead;
     while(originalnode!=NULL && clonenode!=NULL){
         originalnode->next=originalnode->next?originalnode->next->next:originalnode->next;
         originalnode=originalnode->next;

         clonenode->next=clonenode->next?clonenode->next->next:clonenode->next;
         clonenode=clonenode->next;
     }

     return clonehead;

}