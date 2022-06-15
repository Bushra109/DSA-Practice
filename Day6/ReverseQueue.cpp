#include<bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q)
{
    stack<int> s;

    while(!q.empty()){
      int num=q.front();
      s.push(num);
      q.pop();
    }

    while(!s.empty()){
        int num=s.top();
        q.push(num);
        s.pop();
    }
    
   return q;
}
    