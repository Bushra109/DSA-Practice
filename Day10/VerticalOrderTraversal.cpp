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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //a map to store x axis y axis and nodes in y axis
        map<int , map<int , multiset<int>>> nodes;
         //queue to store each node with its x axis and x axis values
         queue<pair<TreeNode * , pair<int , int > > > q;
        
        //now insert the first root node into queue;
        q.push({root , {0,0}});

        while(!q.empty()){
            auto qtop= q.front();
            q.pop();
            TreeNode * temp = qtop.first;

            int x = qtop.second.first;
            int y = qtop.second.second;

            nodes[x][y].insert(temp->val);

            if(temp->left) q.push({temp->left , {x-1 , y+1}});
            if(temp->right) q.push({temp->right , {x+1 , y+1}});
        }
       vector<vector<int>> ans;
       for(auto p : nodes){
        vector<int> col;

       for (auto setx: p.second) {
           col.insert(col.end(), setx.second.begin(), setx.second.end());
       }
       ans.push_back(col);
       }
       return ans;
    }
};