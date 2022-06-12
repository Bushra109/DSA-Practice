#include<bits/stdc++.h>
using namespace std;
void solve(stack<int>&inputStack,int count,int size){
if(count==size/2){
    inputStack.pop();
    return;
}
//store the top element which will be poped, so that you can re-add
int num=inputStack.top();
inputStack.pop();

//recursive call
solve(inputStack,count+1,size);

//add the number popped
inputStack.push(num);
}



void deleteMid(stack<int> &inputStack,int N){
int count=0;
solve(inputStack,count,N);
}