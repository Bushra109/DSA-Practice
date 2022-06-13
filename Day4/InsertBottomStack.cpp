#include<bits/stdc++.h>
using namespace std;

void StackBottomInsert(stack<int> &s, int x){

    //when you reach the bottom of stack , insert the x
    if(s.empty()){
        s.push(x);
        return;
    }

//store the number before pop so you can readd
    int num=s.top();
    s.pop();

    //recursive call

    StackBottomInsert(s,x);

    //when you return ad the element back
     s.push(num);
}