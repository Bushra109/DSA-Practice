#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

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
//approach 1 - to store the linkedlist data in array and check pallindrome
bool checkPalindrome1(Node* list){
vector<int> arr;
Node* temp=list;
while (temp!=0){
    arr.push_back(temp->data);
    temp=temp->next;
}
int s=0;
int e=arr.size()-1;
while(s<=e){
    if(arr[s]!=arr[e])
    return false;

    s++;
    e--;
}
return true;

}
Node* getMiddle(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next){
         fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}
Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
while(curr!=NULL){
     next=curr->next;
     curr->next=prev;
     prev=curr;
     curr=next;
}
return prev;
}
bool checkPalindrome2(Node* head){

        if(head -> next == NULL) {
            return true;
        }
    //get middle node    
    Node* mid=getMiddle(head);
    
    //divide into two parts
    Node* temp=mid->next;

    //reversing the second part
    mid->next=reverse(temp);

    //comparing both parts

    Node* head1=head;
    Node* head2=mid->next;

    while(head2!=NULL){
        if(head1->data!= head->data)
        return false;

        head1=head1->next;
        head2=head2->next;
    }

    //bringing back the original linkedlist
      temp = mid -> next;
      mid -> next = reverse(temp);

    return true;
}
