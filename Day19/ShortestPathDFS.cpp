#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
void findTopoSort(stack<int> &topo ,vector<pair<int,int>> adj[] ,  int node ,vector<int>& visited ){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it.first])
        findTopoSort(topo,adj,it.first,visited);
    }
    topo.push(node);
}
vector<int> shortestPath(int src,int n, vector<pair<int,int>> adj[]){
vector<int> visited(n-1,0);
stack<int> topo;
for(int i =0;i<n;i++){
    if(!visited[i]){
        findTopoSort(topo,adj,i,visited);
    }
}
vector<int> dist(n-1,INT_MAX);
dist[src]=0;
while(!topo.empty()){
    int node=topo.top();
    topo.pop();
    if(dist[node]!=INT_MAX){
        for(auto it: adj[node]){
            if(dist[node]+it.second < dist[it.first]){
                dist[it.first]=dist[node]+it.second;
            }
        }
    }
}
return dist;
}
};