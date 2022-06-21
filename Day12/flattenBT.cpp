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
 TreeNode* prev=NULL;
void flatten(TreeNode* root){
   if(root==NULL)
       return;
    //go to extream right
    flatten(root->right);
    //comeback and move to left
    flatten(root->left);
    
    //appoint the right to previous 
    root->right=prev;
    root->left=NULL;
    
    prev=root;
}
};