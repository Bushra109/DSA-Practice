#include<stdio.h>
#include<unordered_map>
using namespace std;
class Node
    {
    public:
        int data;
        Node *next;
        Node* random;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
Node* insertTail(Node* head, Node* tail, int val){
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
Node* cloneLL(Node* head){

    //create a clone list
    Node* clonehead=NULL;
    Node* clonetail=NULL;

    //copy the contents of original ll to clone ll
    Node* temp=head;
    while(temp!=NULL){
        insertTail(clonehead,clonetail,temp->data);
        temp=temp->next;
    }

    //creating a map to match the original values to clone values
    unordered_map<Node*,Node*> oldToNew;

    Node* originalNode=head;
    Node* cloneNode=clonehead;

    while(originalNode!=NULL){
        oldToNew[originalNode]=cloneNode;
        originalNode=originalNode->next;
        cloneNode=cloneNode->next;
    }
    //bringing back the head to initial position
    originalNode=head;
    cloneNode=clonehead;


    //finding the random links using map
    while(originalNode!=NULL){
        cloneNode->random=oldToNew[originalNode->random];
        originalNode=originalNode->next;
        cloneNode=cloneNode->next;
    }

    return clonehead;
    

}