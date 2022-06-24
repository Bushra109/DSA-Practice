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
    private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
public:
  void inorder(TreeNode* node){
        if(node==NULL) return ;
        inorder(node->left);
        // when you reach the root node the check if its value is smaller than the previous val bcoz inorder stores values in increasing order
        if(prev != NULL && (node->val < prev->val)){
            if(first == NULL){
                //if its the first violation the store both the elements ie previous and current
                first=prev;
                middle=node;
            }
            //if its secong violation then store the current node
            else
                last=node;
            
        }
        //update the previous to current node before moving forward
        prev=node;
        inorder(node->right);
    }   
    
    void recoverTree(TreeNode* root) {
        
        first=middle=last=NULL;
        prev= new TreeNode(INT_MIN);
        inorder(root);
        //if the first and last node are filled the swap them 
        if(first && last)swap(first->val , last->val);
        else if(first && middle)swap(first->val , middle->val);
        
    }
};