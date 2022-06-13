#include<bits/stdc++.h>
using namespace std;

void SortInsert(stack<int> &st , int x){
    if(st.empty() || st.top()<x){
        st.push(x);
        return;
    }


    //when not found store the top element and go on searching the position to insert
    int num=st.top();
    st.pop();

    SortInsert(st,x);

    //after you return a sorted stack,push back the element you poped

    st.push(num);
}


void SortStack(stack<int> &st){
    if(st.empty()){
        return;
    }

    int num=st.top();
    st.pop();

    //recursive call to return a sorted stack
    SortStack(st);

    //now add the element in sorted order
    SortInsert(st,num);

}