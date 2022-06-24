#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
void dfsTraversal(int node , vector<int> adj[] , vector<int> &traversal  , vector<int> &visited ){

//first push the node into traversal
traversal.push_back(node);
visited[node]=1;

//now iterate over all the adjacency nodes 
for(auto it: adj[node]){
//for every  element encountered unvisited , recursively call function for each
if(!visited[it]){
    dfsTraversal(it , adj , traversal , visited);
}
}

}
vector<int> dfsGraph(int n , vector<int> adj[]){
    vector<int> traversal;
    vector<int> visited(n , 0);
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfsTraversal(i, adj , traversal , visited);
        }
    }
    return traversal;
}
};