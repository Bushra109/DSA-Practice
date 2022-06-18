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

//we just need to check if their pre / in / post order travesral are same at each step
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p==NULL) || (q==NULL))
            return(p==q);
        else
            return(p->val==q->val) && (isSameTree(p->left , q->left)) && (isSameTree(p->right , q->right));
    }
};