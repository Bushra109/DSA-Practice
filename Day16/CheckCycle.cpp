#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//cycle detection in ubdirected graph
    bool checkCycle(int i , vector<vector<int>>& prerequisites , vector<int> visited){
        queue<pair<int , int>> q;
        
        visited[i]=1;
        q.push({i , -1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
           for(auto it : prerequisites[node]){
               if(!visited[it]){
                   visited[it]=1;
                   q.push({it , node});
               }
               else if(parent != it){
                   return true;
               }
           }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses , 0);
        
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(checkCycle(i , prerequisites , visited ))
                    return false;
            }
        }
        return true;
    }
};