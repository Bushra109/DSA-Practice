 #include<bits/stdc++.h>
 using namespace std;

 vector<int> repeatedNumber(const vector<int> &A){
int xor_op=A[0];
int set_bit;

int n=A.size();

//fist xor operation on all elements of  array
for(int i=1;i<A.size();i++){
    xor_op=xor_op ^ A[i];
}
//the xor operation on all possible (ie 1-n) numbers of array
for(int i=1;i<=n;i++){
    xor_op=xor_op ^ i; //this will cancel out the numbers occuring twice
}

//on xor operation only the numbers that occur once(missing) and thrice(repeating) are left ie x ^ y

//Now find the rightmost set bit of final xor operation ie x^y

set_bit = xor_op & ~(xor_op - 1);

//divide all the numbers in two buckets..
//1st bucket-whose set bit matches 
//2nd bucket whose set bit does not match

int x=0,y=0;

//iterate for array
for(int i=0;i<n;i++){
    if(A[i] & set_bit)
    //it lies in 1st bucket
    x=x^A[i];

    else
    //it lies in second bucket
    y=y^A[i];
}

//iterate for numbers
for(int i=0;i<=n;i++){
    if(i & set_bit)
    //it lies in 1st bucket
    x=x^i;

    else
    //it lies in second bucket
    y=y^i;
}

//now x and y have our answers

//to find which among x and y is repeating
int count=0;
for(int i=0;i<n;i++){
    if(A[i]==x)
    count++;
}

if(count!=0)
return {x,y};

else
return{y,x};





 }