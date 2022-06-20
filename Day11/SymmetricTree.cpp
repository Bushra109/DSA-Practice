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
    bool checkSymmetric(TreeNode * leftroot , TreeNode * rightroot){
        if(leftroot==NULL || rightroot==NULL)
            return leftroot==rightroot;
        //checking if both the values are same
       if(leftroot -> val != rightroot -> val) return false;
       
       //moving towards left->left and right->right (mirror is laterally inverted)
       //then moving towards left->right and right->left
        return checkSymmetric(leftroot->left , rightroot->right) && checkSymmetric(leftroot -> right , rightroot -> left);
    }
    bool isSymmetric(TreeNode* root) {
        return root==NULL || checkSymmetric(root -> left , root-> right);
    }
};