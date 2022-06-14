//https://leetcode.com/problems/unique-paths/
#include<bits/stdc++.h>
using namespace std;

//approach1:Brute Force using Recursion
int countPaths1(int i,int j,int n,int m)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        else return countPaths1(i+1,j,n,m)+countPaths1(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) {
       return countPaths1(0,0,m,n);
    }

//approach 2 :Brute Force using recursion and implementing Dynamic Programing
int countPaths2(int i,int j,int n,int m,vector<vector<int>> &dp)
    {   //when you reach destination return 1
        if(i==(n-1)&&j==(m-1)) return 1;
        //when pointer exceeds the possible path return zero
        if(i>=n||j>=m) return 0;
        //as it is not -1 the path has already been visited and total number has been stored in dp[i][j]
        if(dp[i][j]!=-1) return dp[i][j];


         //if dp[i][j]==-1 then that path is not visited
        //count possible number of path from down(ie i+1) and right(ie j+1);
     else return dp[i][j]=countPaths2(i+1,j,n,m,dp)+countPaths2(i,j+1,n,m,dp);
        
    }


    int uniquePaths(int m, int n) {

        //initialise a 2d matrix dp
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       
        //dp[1][1]=1;

        //count total number of paths possible
       int num=countPaths2(0,0,m,n,dp);
        if(m==1&&n==1)
            return num;
        return dp[0][0];
    }


    //approach 3: Using permutations and combinations
  int uniquePaths(int m, int n) {

            //observe total number of steps is always m+n-2

            //we can figure out we need n-1 no. of rightward direction 
            // m-1 no. of downward direction to reach the endpoint.

            // calculate the combinations ( ie: m+n-2Cn-1 or m+n-2Cm-1) we’ll get the total number of paths.
            int N = n + m - 2;
            int r = m - 1; 
            //taking res double as we have to multiply and divide
            double res = 1;
            
            //calculating the combination
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;

            //returning result in int form
            return (int)res;
    }