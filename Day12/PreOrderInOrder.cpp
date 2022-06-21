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
 TreeNode * buildTheTree(vector<int>& preorder , int preStart , int preEnd ,
                            vector<int> &inorder , int inStart , int inEnd , 
                            map<int , int > &inmap  )
     {
          if(preStart>preEnd || inStart>inEnd) return NULL;
        
        TreeNode * root= new TreeNode(preorder[preStart]);
        
        //finding that root in inorder traversal
        int inRoot=inmap[root->val];
        //calculating the nodes left by {the difference btw instart and inroot}
        int nodesLeft=inRoot - inStart;

        root->left=buildTheTree(preorder , preStart+1 , preStart+nodesLeft,
                                inorder , inStart , inRoot-1,inmap );
        
        root->right=buildTheTree(preorder , preStart+nodesLeft+1,preEnd,
                                 inorder , inRoot+1,inEnd , inmap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int preStart = 0, preEnd = preorder.size() - 1;
		int inStart = 0,  inEnd = inorder.size()  -  1;
        map<int , int > inmap;
        for(int i=0;i<=inEnd;++i){
          inmap[inorder[i]]=i;
        }

        TreeNode * root = buildTheTree(preorder , preStart , preEnd , inorder , inStart , inEnd , inmap);
        return root; 
    }
   
};