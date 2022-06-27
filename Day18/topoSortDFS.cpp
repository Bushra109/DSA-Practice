#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
void findTopoSort(int i ,stack<int>& st , vector<int> adj[],vector<int>& visited){
int node=i;
visited[node]=1;
for(auto it:adj[node]){
    if(!visited[it]){
        findTopoSort(it , st , adj , visited);
    }
}
st.push(node);
}
public:
vector<int> topoSort(int n , vector<int> adj[]){
    stack<int> st;
    vector<int> ans;
    vector<int> visited(n-1,0);
    for(int i=0; i<n;i++){
       if(!visited[i]){
        findTopoSort(i,st,adj,visited);
       }
    }
    while(!st.empty()){
        
    }
}


};