#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key)
        return newRoot(root);
        
        TreeNode* curr=root;
        while(curr!=NULL){
            //moving to left as we need a smaller number
            if(curr->val > key){
            //checking if the next left value if key
            if(curr->left != NULL && curr->left->val==key){
                //we attach a new root instead of existing node
                curr->left=newRoot(curr->left);
                break;
            }
            else{
                //we move till we find the required node
                curr=curr->left;
            }
            }
            else{
                //moving to right as we need a greater number
                if(curr->right != NULL && curr->right->val==key){
                    curr->right=newRoot(curr->right);
                    break;
                }
                else{
                    curr=curr->right;
                }
            }
            return root;
        }

    }
    TreeNode* newRoot(TreeNode* root){

         if(root->left == NULL)
         return root->right;
         if(root->right==NULL)
         return root->left;

         //finding the right child which will be detached 
         TreeNode* RightChild=root->right;
         //finding the last node in left subtree - where we can attach the right cub tree bcoz obviously all the numbers in right subtree will be greater than the last node of left sub tree
         TreeNode* lastNode=getLastNode(root->left);
         lastNode->right=RightChild;

         //after attaching the right subtree to last left , we have one tree whose root if the left root
         return root->left;
    }
    TreeNode* getLastNode(TreeNode* root){
        TreeNode* temp=root;
        while(temp){
            temp=temp->right;
        }
        return temp;
    }
};