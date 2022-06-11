#include<stdio.h>
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
Node* reverse(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;

    while(curr!=NULL){
        next=head->next;
        head->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void insertAns(Node* head,Node* tail,int val){
Node* temp= new Node(val);
if(head==NULL){
    head=temp;
    tail=temp;
}
else{
    tail->next=temp;
    tail=temp;
}
}

Node* add(Node* first, Node* second){
    int carry=0;
    //declaring head and tail of ans
    //head to insert the first value and tail to insert the next values
    Node* anshead=NULL;
    Node* anstail=NULL;

    while(first!=NULL && second!=NULL){
        //finding sum
        int sum=carry+first->data+second->data;

        //extracting digit
        int digit=sum%10;

        //inserting digit at answer linkedlist
        insertAns(anshead , anstail , digit);
        
        //finding carry value
        carry=sum/10;

        //updating first and second
        first=first->next;
        second=second->next;
    }

    //managing exceptional cases

    //1. first becomes null and second has some value
     while(second!= NULL){
        int sum=carry+first->data;
        int digit=sum/10;
        insertAns(anshead , anstail , digit);
        carry=sum/10;
       first=first->next;
    }


    // 2. second becomes null and first has some values
    while(second!= NULL){
        int sum=carry+second->data;
        int digit=sum/10;
        insertAns(anshead , anstail , digit);
        carry=sum/10;
        second=second->next;
    }

    //3. carry exists while both have ended values eg(9+9)

    while(carry!=0){
        int sum=carry;
        int digit=sum/10;
        insertAns(anshead , anstail , digit);
        carry=sum/10;
    }

    return anshead;



}



/// in the above function instead of using 3 loops you can use 1 loop for solving
/* Node* add(struct Node* first, struct Node* second) {
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
                
            int val2 = 0;
            if(second !=NULL)
                val2 = second -> data;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            
            //create node and add in answer Linked List
            insertAns(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        }
        return ansHead;
    }
    */

Node* add2numbersLL(Node* first,Node* second){


    //step 1 - to reverse both the numbers (as we add numbers from right side)
    first=reverse(first);
    second=reverse(second);

    //adding two linked list
    Node* ans=add(first,second);

    //reversing the answer
    ans=reverse(ans);

    return ans;
}