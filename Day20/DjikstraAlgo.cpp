#include<bits/stdc++.h>
using namespace std;
class Solution{
void djikstraAlgo(int src,int n ,vector<pair<int,int>> graph[]){
priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
// we store a pair in a vector container with greater operation which makes a min heap

vector<int> dist(n+1,INT_MAX);
dist[src]=0;
pq.push({0,src});  //storing distance and node

while(!pq.empty()){
    int distance=pq.top().first;
    int node=pq.top().second;
    pq.pop();

    for(auto it: graph[node]){
      int nextNode=it.first;
      int nextDist=it.second;

      if(dist[nextNode]> distance + nextDist ){
         dist[nextNode] = distance + nextDist;
         pq.push({dist[nextNode] , nextNode});
      }
    }
}

}
};