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

vector<int> BottomView(TreeNode * root){
    vector<int> ans;
    if(root==NULL){
       return ans;
    }
    //map to keep nodes and their line number(x axis)
    map<int, int> mp;
    //queue to iterate over all nodes of tree with their line (x axis) number
    queue<pair<TreeNode * , int >> q;

    q.push({root , 0});

    while(!q.empty()){
        //taking the top value of queue
        auto p = q.front();
        q.pop();
        //taking the node 
        TreeNode * node = p.first;
        //taking the line number
        int line = p.second;
        //inserting the node->val in its respective line number
        mp[line]=node->val;

        if(node->left)q.push({node->left , line-1});
        if(node->right)q.push({node->right , line+1});

    }
    
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}


};