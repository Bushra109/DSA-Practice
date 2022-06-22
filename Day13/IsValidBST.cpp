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
//we need to maintain a range withing which the val must fall so as to make a valid binary tree
    bool isValidBST(TreeNode* root) {
       if(root->left ==NULL && root->right==NULL) return true;
       return isValid(root, LONG_MIN, LONG_MAX);
    }
    bool isValid(TreeNode* root , long min , long max){
        if(root==NULL)return true;
        if(root->val <= min || root->val >= max )
            return false;
        return isValid(root->left , min , root->val) && isValid(root->right , root->val , max);
    }
};