#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
bool detectCycleBFS(int node , int parent , vector<int> adj[] , vector<int>& visited ){
    visited[node]=1;
    for(auto it :adj[node]){
        if(!visited[it]){
           return   detectCycleBFS(it , node , adj , visited);
        }
        else if (it != parent){
        return true;
        }
    }
    return false;
}

public:
bool checkCycle(int N , vector<int> adj[]){
    vector<int> visited(N+1 , 0);
    for(int i=1 ; i<=N; i++){
        if(!visited[i]){
            return detectCycleBFS(i , -1 , adj , visited);
        }
    }

return false;
}
};


