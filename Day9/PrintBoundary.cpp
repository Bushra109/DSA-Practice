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

class Solution{
    private:
    bool isLeaf(TreeNode * root) {
  return !root -> left && !root -> right;
}
void addLeftBoundary(TreeNode* root , vector<int> &ans){
//we need to add the left boundary except the leaf nodes
TreeNode* curr=root->left;
while(curr!=NULL){
    //check if its not a leaf node then add it
    if(!isLeaf(curr))ans.push_back(curr->val);
    //updating the curr
    if(curr->left)curr=curr->left;
    else
    curr=curr->right;
}

}
void addLeaves(TreeNode* root , vector<int> &ans ){
//just do inorder traversal and check the leaf nodes
if(isLeaf(root)) ans.push_back(root->val);
addLeaves(root->left,ans);
addLeaves(root->right,ans);
}
void addRightBoundary(TreeNode* root , vector<int> &ans){
TreeNode* curr=root->right;
//ccreating a right vector which will keep boundary in sequence and then we will reverse it and add in ans
vector<int> right;
while(curr!=NULL){
    if(!isLeaf(curr))right.push_back(curr->val);
    if(curr->right)curr=curr->right;
    else
    curr=curr->left;
}
//now copy the elements of right vector in reverse order
for(int i=right.size()-1;i>=0;--i){
    ans.push_back(right[i]);
}
}
    public:
vector<int> BoundaryTraversal(TreeNode* root ){
    vector<int> ans;
    if(!root) return ans;
    if(isLeaf(root))ans.push_back(root-> val);

    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
}
};