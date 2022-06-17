#include<bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}


class Solution{
    public:
    vector<vector<int>> PreInPostTraversal(node * root){

        //declaring a 2d array tos trore pre in and post
        vector<vector<int>> ans;

        //declaring a stack of data type pair which will store the node and its corrseponding visit
         stack < pair < node * , int >> s;
        vector<int> pre , in , post;
        if(root==NULL)
        return ans;
        //pushing 1st node with 1 as its visit
        s.push({root,1});

        while(!s.empty()){
            //taking the top elemnt of stack
            auto it = s.top();
            s.pop();
            
            //checking the number of visit (if its 1 the go to preorder)
            if(it.second==1){
                pre.push_back(it.first->data);
                //increasing the number of visit
                it.second++;
                //pushing back the node with updated visit
                s.push(it);
                
                //if the left exists pushing into stack
                if(it.first -> left!= NULL)
                 s.push({
          it.first -> left,
          1
        });

            }

             //checking the number of visit (if its 2 the go to inorder)
             if(it.second==2){
                in.push_back(it.first->data);
                it.second++;
                s.push(it);

                if(it.first -> right!= NULL)
                s.push({it.first->right , 1});
                
            }

             //checking the number of visit (if its 3 the go to postorder)
            if(it.second==3)
            post.push_back(it.first->data);
        }
      ans.push_back(pre);
      ans.push_back(in);
      ans.push_back(post);

return ans;
    }
};