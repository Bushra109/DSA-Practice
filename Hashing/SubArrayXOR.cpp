#include<bits/stdc++.h>
using namespace std;

int countSubarray(vector<int> nums , int K){
    int n = nums.size();
    unordered_map<int , int> mp;
    int xorr = 0;
    int count=0;
    for(int i=0;i<n;i++){
        xorr = xorr ^ nums[i];
        if(xorr == K){
            count++;
        }
        if(mp.find(xorr) != mp.end()){
            count = count + mp[xorr ^ K];
        }

        mp[xorr] = mp[xorr]+1;
    }
    return count;
}