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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        //as long as both the numbers lie on same side continue
        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right , p ,q);
        }
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left , p ,q);
        }
        //when both numbers lie on different side that root is the LCA
        return root;
    }
};