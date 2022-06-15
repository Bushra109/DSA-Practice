//https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1/
#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    for(int i=0;i<k;i++){
        int num=q.front();
        q.pop();
        s.push(num);
    }

    while(!s.empty()){
        int ele=s.top();
        s.pop();
        q.push(ele);
    }
    int n=q.size();
    for(int i=0;i<n-k;i++){
        int num=q.front();
        q.pop();
        q.push(num);
    }
    return q;
}