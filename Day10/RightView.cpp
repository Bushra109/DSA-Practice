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

//approach1
    vector<int> rightSideView1(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        //map to keep track of level and its respective data
         map<int , int> mp;
        
        //queue to iterate over all the nodes
        queue<pair<TreeNode*, int>> q;

        q.push({root , 0});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode * node = p.first;
            int level = p.second;

            mp[level]=node->val;

            if(node->left)q.push({node->left , level+1});
            if(node->right)q.push({node->right , level+1});
        }

      for(auto it : mp){
        ans.push_back(it.second);
      }
     return ans;
    }


    //approach 2
    void recursion(TreeNode *root, int level, vector<int> &res)
    {   //traversing in reverse pre order
        if(root==NULL) return ;
        //comparing with size of vector (if its same so we have encountered a new level and we need to add it)
        if(res.size()==level) res.push_back(root->val);
        //going to right first
        recursion(root->right, level+1, res);
        //going to left
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView2(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};