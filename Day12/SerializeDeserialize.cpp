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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        
        string s ="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
           TreeNode* curNode = q.front();
           q.pop();
           if(curNode==NULL) s.append("#,");
           else s.append(to_string(curNode->val)+',');
           if(curNode != NULL){
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }
        return s;

            
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if( data=="" ) return NULL;
       stringstream s(data);
       string str;
       //get the str from s till you dont encounter ','
       getline(s, str, ',');
       //the tree node will store the integer from of str
       TreeNode* root=new TreeNode(stoi(str));
       queue<TreeNode*> q;
       q.push(root);

       while(!q.empty()){
          TreeNode* curr= q.front();
          q.pop();
          //get the str from s till you dont encounter ','
          getline(s, str, ',');
          
          if(str=="#")curr->left=NULL;
          else{
            TreeNode* leftNode = new TreeNode(stoi(str));
            curr->left=leftNode;
            q.push(curr->left);
          }
          getline(s, str, ',');
          
          if(str=="#")curr->right=NULL;
          else{
            TreeNode* rightNode = new TreeNode(stoi(str));
            curr->right=rightNode;
            q.push(curr->right);
          }
       }
     return root;
    }
};
