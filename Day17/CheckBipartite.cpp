#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool check(int node , vector<vector<int>>& graph ,  vector<int>& colors ){
        colors[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(auto it : graph[ele]){
                if(colors[it]==-1){
                    colors[it]= 1- colors[ele];
                    q.push(it);
                }
                else if(colors[it]==colors[ele])
                        return false;
                
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> colors(N , -1);
        for(int i=0;i<N ; i++){
            if(colors[i]==-1){
                if(!check(i , graph , colors))
                    return false;
            }
        }
        return true;
    }
};