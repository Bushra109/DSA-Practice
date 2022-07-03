#include<bits/stdc++.h>
using namespace std;

int lengthSubArray(vector<int> nums ){
    int n= nums.size();
    int sum=0;
    int length=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        sum=sum+nums[i];
        if(sum==0){
            length = i+1;
        }
        else{
            if(mp.find(sum) != mp.end()){ //if you find the sum in the map
                length = max( length , i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
    }
    return length;
}