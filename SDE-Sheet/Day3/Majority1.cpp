 #include<bits/stdc++.h>
 using namespace std;

//approach1
 int majorityElement1(vector<int>& nums) {
        int x=nums.size()/2;
        int count=0,ele=nums[0];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            ele=nums[i];
            if(ele==nums[i+1])
                count++;
            else{
                count++;
                if(count>x)
                    return ele;
                count=0;
            }
        }
        return ele;
    }

 //Moore's voting algorith
  int majorityElement(vector<int>& nums){
    int count=0;
    int candidate=0;
    for(int n :nums){
      if(count==0){
        candidate=n;
      }
      if(n==candidate) count+=1;
      else
      count-=1;

    }
    return candidate;
  }