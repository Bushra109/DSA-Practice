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
//we have to maintain an upperBound to check and insert the node , upper bound for left will be root node and upperBound for right will be the same upperbound as of root node
    TreeNode* createBST( int upperBound , vector<int>& preorder ,int &i ){
        if(i>=preorder.size() || preorder[i] > upperBound)
            return NULL;

        //creating the node
        TreeNode* node=new TreeNode(preorder[i]);
        //moving to next element in preorderlist
        i++;
        //inserting the left and right
        node->left=createBST(node->val , preorder , i );
        node->right=createBST(upperBound , preorder , i );
        //returning the root
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
       return createBST(INT_MAX , preorder , i);
    }
};