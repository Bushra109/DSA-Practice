// problem link - https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/
#include<bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int> >& M,int a,int b, int n){
    if(M[a][b]==1)
    return true;

    else
    return false;
}

 int celebrity(vector<vector<int> >& M, int n) 
    {
        //use a stack 
        stack<int> s;

        //push all the numbers in stack 
        for(int i=0;i<n;i++){
          s.push(i);
        }
        
        while(s.size()>1){
            //pop out two elements and check their relationship
            int a=s.top();
            s.pop();

            int b=s.top();
            s.pop();

           //check relationship

           if(knows(M,a,b,n)){
            s.push(b);
           }
           else{
            s.push(a);
           }

        }

        int ans=s.top();

        //now check if this ans satisfies all condition of celebrity

        //1. All corresponding row elements should be zero
        int zeroCount=0;
        for(int i=0;i<n;i++){
            if(M[ans][i]==0)
            zeroCount++;
        }
        if(zeroCount!=n)
        return -1;                       //it didnt satisfy the 1st condition so return -1

        int oneCount=0;
        for(int i=0;i<n;i++){
            if(M[i][ans]==1)
            oneCount++;
        }
        if(oneCount!=n-1)              //total number of 1s in column is n-1 as there will be one 0 in diagonal
        return -1;

        return ans;
    }