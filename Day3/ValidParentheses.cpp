 #include<bits/stdc++.h>
 using namespace std;
 
 bool isValid(string expression) {
        
  	 stack<char> s;
     for(int i=0; i<expression.length(); i++) {
         
         char ch = expression[i];
         
         //if opening bracket, stack push
         
         if(ch == '(' || ch == '{' || ch == '['){
             s.push(ch);
         }
         else
         {
                //if close bracket, stacktop check and pop
                //check if stack is empty
             if(!s.empty()) {
                  char top = s.top();
                  if( (ch == ')' && top == '(') || 
                     ( ch == '}' && top == '{') || 
                     (ch == ']' && top == '[') ) {
                      s.pop();
                  }
                 else
                 {
                     return false;
                 }
             }
             //if not empty and closing bracket , then its not valid
             else
             {
                 return false;
             } 
         }  
     }
    
    if(s.empty())
        return true;
    else
        return false;
    }