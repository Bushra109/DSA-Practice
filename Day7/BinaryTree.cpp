#include<bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

//Root Left Right
void preorder(node * curr , vector<int> PreOrder){
    if(curr==NULL)
    return;

    PreOrder.push_back(curr -> data);
    preorder(curr -> left , PreOrder);
    preorder(curr -> right , PreOrder);

}

//left root right
void inorder(node * curr , vector<int> InOrder){
    if(curr==NULL)
    return;

    inorder(curr -> left , InOrder);
    InOrder.push_back(curr -> data);
    inorder(curr -> right , InOrder);

}

//left right root
void postorder(node * curr , vector<int> PostOrder){
    if(curr==NULL)
    return;

    postorder(curr -> left , PostOrder);
    postorder(curr -> right , PostOrder);
    PostOrder.push_back(curr -> data);

}