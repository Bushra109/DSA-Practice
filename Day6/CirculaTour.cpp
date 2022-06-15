//https://practice.geeksforgeeks.org/problems/circular-tour/1

#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

class solution{
public:
int tour(petrolPump p[],int n){

    //balance to calculate remaining petrol
    int balance=0;
    int start=0;
    //deficit to calculate amount of petrol required to cover that particular portion so that we do not have to iterate over it again
    int deficit=0;

    for(int i=0;i<n;i++){
        balance = balance + p[i].petrol - p[i].distance;
        if(balance<0){
          start=i+1;
          deficit=balance; //update the deficit as this much amount of petrol is deficit
        }
    }
    //now check if the deficit and balance sum greater than =0 which proves the vehicle can successfully reach the destination
    if(deficit+balance>=0)
    return start;

    else 
    return -1;


}
};