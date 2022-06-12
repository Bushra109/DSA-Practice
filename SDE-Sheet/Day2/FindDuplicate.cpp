 #include<bits/stdc++.h>
 using namespace std;


//approach 1 - using hash table
  int findDuplicate1(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        //push back all the numbers into hash table
        for(int i=0;i<n;i++)
            arr.push_back(i+1);
        //iterate over the array and cancel out the element on 1st encounter
        for(int i=0;i<n;i++){
            //second encounter where the element has already been cancelled
            if(arr[nums[i]]== -1)
                return nums[i];
            else
            //first encounter - cancel elements
                arr[nums[i]]=-1;
        }
        return -1;
            
        }

//approach 2- LinkedList cycle method (when two pinoters will meet the second time)
int findDuplicate1(vector<int>& nums){
    //take 2 pointers fast and slow
    int fast=nums[0];
    int slow=nums[0];
    //find the point where they meet 1st time
    do{
        slow=nums[slow];  //moving 1 step
        fast=nums[nums[fast]];   //moving 2 step
    }
    while(fast!=slow);

    //after the meet bring the fast pointer to arr[0]

    fast=nums[0];

    //again iterate and find the collision point
    while(fast!=slow){
         slow=nums[slow];  //moving 1 step
        fast=nums[fast];   //moving 1 step
    }

    return fast;
}
