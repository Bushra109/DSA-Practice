#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/largest-rectangle-in-histogram/

vector<int> nextSmallerIndex(vector<int> arr, int n){
    stack<int> s;
    //stack will contain the indexes
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        //if the value in the corresponding stack array is greater than the value of arr[i]
        //stack ka index element bada hai
        while(s.top()!= -1 && arr[i]<=arr[s.top()] ){
            s.pop();
        }
        //stack ka index element chota ho gaya
        ans[i]=s.top();    //store the index
        s.push(i);        //push the new index
    }
    return ans;
}

vector<int> previousSmallerIndex(vector<int> arr, int n){
    stack<int> s;
    //stack will contain the indexes
    s.push(-1);
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        //if the value in the corresponding stack array is greater than the value of arr[i]
        //stack ka index element bada hai
        while(s.top()!= -1 && arr[i]<=arr[s.top()] ){
            s.pop();
        }
        //stack ka index element chota ho gaya
        ans[i]=s.top();    //store the index
        s.push(i);        //push the new index
    }
    return ans;
}

 int largestRectangleArea(vector<int>& heights) {

int n=heights.size();

vector<int> next(n);
next=nextSmallerIndex(heights,n);

vector<int> previous;
previous=previousSmallerIndex(heights,n);

int maxArea=INT_MIN;

for(int i=0;i<n;i++){
    int length=heights[i];
    int breadth=next[i]-previous[i]-1;     //breadth formula n-p-1
    int area=length * breadth;
    maxArea=max(area,maxArea);
}


return maxArea;


}