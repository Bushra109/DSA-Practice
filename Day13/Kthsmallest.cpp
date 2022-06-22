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
	int ans;
	int ct = 0;
    //inorder traversal of a BST always gives the sorted form of nodes
	void inOrder(TreeNode* root, int k) {
		if (!root) return;
		inOrder(root->left, k);
		ct++;
		if (ct == k) {
			ans = root->val;
			return;
		}
		inOrder(root->right, k);
	}
public:
	int kthSmallest(TreeNode* root, int k) {
		inOrder(root, k);
		return ans;
	}
};