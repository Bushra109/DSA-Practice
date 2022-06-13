#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmaller(vector<int> &nums){
    int n=nums.size();
    vector<int> ans(n);
    //initialise a stack and push -1
    stack<int> s;
    s.push(-1);

    //start from the rightmost part
    for(int i=n-1;i>=0;i--){
    //for each element check if its smaller than the top value of stack

    //possiblity 1 - It is not smaller

    while(s.top()>=nums[i]){
        s.pop();
    }
    //when we come out the value at top is smaller

    //possiblity 2- the top value is smaller
    ans[i]=s.top();
    s.push(nums[i]);

    }
    return ans;
}