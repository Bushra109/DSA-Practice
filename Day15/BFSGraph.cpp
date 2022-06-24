#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
vector<int>bfsGraph(int n , vector<int> adj[]){
    //to keep the traversal
    vector<int> traversal;
    //to keep track of nodes visited , we declare a vector of size n initialised with 0
    vector<int> visited(n , 0);

    for(int i=0;i<n;i++){
        //if the node is not visited then only enter the body
       if(!visited[i]){
        //we declare a queue to store all the nodes of that one compartment
        queue<int> q;
        //we push the element into queue
        q.push(i);
        visited[i]=1;
        //
        while(!q.empty()){
          int node = q.front();
          q.pop();
          //push the node into traversal
          traversal.push_back(node);
          //now iterate over all the djacent nodes and push them
          for(auto it : adj[node]){
           q.push(it);
           visited[it]=1;
          }
        }
       }

    }
   return traversal;
}
};