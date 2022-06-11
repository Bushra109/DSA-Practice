#include<bits/stdc++.h>
using namespace std;
  vector<vector<int>> merge(vector<vector<int>>& intervals) {

      vector<vector<int>> mergedIntervals;

      //handling edge case
        if(intervals.size()==0)
            return mergedIntervals;

        //sorting all intervals so that those who merge will be places consecutive
        sort(intervals.begin(),intervals.end());

        //storing the initial interval
        vector<int> tempInterval=intervals[0];

        //iterating through the intervals and comparing
        for(auto it : intervals){

            //if the interval merges update the right side value
            if(it[0]<=tempInterval[1])
            {
                tempInterval[1]=max(it[1],tempInterval[1]);
            }

            //if it not merges, the next intervals will also not merge. So stop and insert into final ans
            else{
                mergedIntervals.push_back(tempInterval);
                tempInterval=it;
            }
            
        }
         mergedIntervals.push_back(tempInterval);
            return mergedIntervals;
    }