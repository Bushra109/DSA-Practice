 #include<bits/stdc++.h>
 using namespace std;

  bool searchMatrix(vector<vector<int>>& matrix, int target){
    int m=matrix.size();
    int n=matrix[0].size();
    
    //creating an imaginary 1d array with all elements sorted where s=0 and e=n*m-1
    int s=0;
    int e=n*m-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        //note that the mid of 1d array can be writted in 2d form where row=mid/n and col=mid%n
        int row=mid/n;
        int col=mid%n;

        //apply binary search
        if(matrix[row][col]==target)
        return true;

        else if(matrix[row][col]>target)
        e=mid-1;

        else
        s=mid+1;

        mid=s+(e-s)/2;
    }
    return false;
  }