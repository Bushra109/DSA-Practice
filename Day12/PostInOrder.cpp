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
	TreeNode* construct_tree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int> &m)
	{
		if (inStart > inEnd || postStart > postEnd) return NULL;

		TreeNode* root = new TreeNode(postorder[postEnd]);

		int poSofRoot = m[postorder[postEnd]];
		// int nPos = m[postorder[postEnd]] - inStart;

		root->left = construct_tree(inorder, inStart, poSofRoot - 1, postorder, postStart ,postStart+poSofRoot-inStart-1 , m);
		root->right = construct_tree(inorder, poSofRoot + 1, inEnd, postorder, postStart +  poSofRoot - inStart, postEnd-1, m);

		return root;
	}
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postStart = 0, postEnd = postorder.size() - 1;
		int inStart = 0,  inEnd = inorder.size()  -  1;

		map<int, int> m;
		for (int i = 0; i <= inEnd; ++i)
		{
			m[inorder[i]] = i;
		}

		return construct_tree(inorder, inStart, inEnd, postorder, postStart, postEnd, m);
    }
};