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
    private:
    //assigning parent nodes to all the nodes
    void mapParent(TreeNode* root ,  unordered_map<TreeNode* , TreeNode*> &parent ){
        //taking a queue to track all the nodes
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            //if it has left , the its the parent of left chils
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
             if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       ///tracking the parent node
       unordered_map<TreeNode* , TreeNode*> parent;
       mapParent(root,parent);
       //tracking the nodes that are visited
       unordered_map<TreeNode* , bool> visited;
       //traversing all the nodes one by one
       queue<TreeNode*> q;
        int distance=0;
        q.push(target);
        visited[target]=true;
        while(!q.empty()){
            //taking all the nodes at once
            int size=q.size();
            //if the distance is attained , then break the loop
            if(distance++==k)break;
            //now iterate over all the nodes of queue
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                //if it has a left child and its not visited
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                    
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                //going in upward direction and cancelling out the parents
                if(parent[curr] && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                }
                
            }  
        }
         vector<int> ans;
         while(!q.empty()){
             ans.push_back(q.front()->val);
             q.pop();
         }
        return ans;
    }
};