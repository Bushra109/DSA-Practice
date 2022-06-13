 #include<bits/stdc++.h>
 using namespace std;
  double myPow(double x, int n) {
        double ans=1.0;
        //take long long to avoid overflow while converting -ve to +ve
        long long power=n;

        //if power is negative convert to positive
        if(power<0)
            power=(-1) * power;
        //run till power !=0
        while(power){
            //when power is odd
            if(power%2){
                ans=ans*x;
                power=power-1;
            }
            //when power is even
            else{
                x=x*x;
                power=power/2;
            }
        }
        //if n is negative x^(-n) is in form of 1/x^n
        if(n<0)ans=(double)(1.0)/(double)(ans);
        return ans;
    }