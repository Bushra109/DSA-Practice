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
bool getPath(TreeNode * root, vector < int > & arr, int x){
//check if root is null
if(root==NULL)return false;
//push the value into array
arr.push_back(root->val);
if(root->val==x)return true;

//if you get the answer fro any of the side return true
if( getPath(root->left,arr,x) || getPath(root->right , arr , x)) return true;
//as you didnt get the answer pop beck the value added
arr.pop_back();
//return false as the value not found
return false;
}