#include<iostream>
using namespace std;

int main(){
 int arr[5] ;
 cout<<"Enter the elements of array:"<<endl;
 for(int i=0;i<5;i++)
     {
         cin>>arr[i];
     }
  int largest=INT_MIN;
  int smallest=INT_MAX;
        for(int i=0;i<5;i++)
        {
            if(arr[i]>largest)
            {
                largest=arr[i];
            }
            if(arr[i]<smallest)
            {
                smallest=arr[i];
            }
        }
        cout<<"The largest number is "<<largest<<endl;
        cout<<"The smallest number is "<<smallest<<endl;
cout<<"\nBushra is active";


return(0) ;
}
