#include <iostream>
#include <stack>
#include <string>

       using namespace std;


int prec(char c) {
    if (c == '^'){
        return 3;
    }
    else if (c == '*' || c == '/'){
        return 2;
    }
    else if (c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
}
}
     int infixToprefix(string s ){
        stack<int> st;
        string res;

   // MAIN FUNCTUIN
   string infixToPrefix (string s)
   {
    reverse(s.begin(),s.end());
    stack<char> st;
     string res; // string result store     
   
     // itrate
     for (i=o;i< s.length();i++){

        // all character condition
        //1// operent
        if (s[i]>='a'&& s[i]<='z' || s[i]>='A' && s[i]<='Z'){
            res += s[i];       // operent print 
        }
       if else (s[i]=='('){ // opening bracket
        s.push(s[i]);
       }
       if else (s[i]==')'){
        while(!st.empty() && st.top()!=')'){
             res+=st.top();
             st.pop();
        }
        if (!st.empty()){
            st.pop();
        
        }
        else{
            while (!st.empty() && prec (st.top()) >=prec(s[i])){
                res+=st.top();
                st.pop;
            }
            st.push(s[i]);
        }
       }
    }
     while (!st.empty())
     {
         res+=st.top();
         st.pop();
     }
    
     reverse (res.begin(),res.end());
     return res;
   
   }

}
int main (){
    cout << infixToPrefix("(a+b*c^(d/e^f)-g)")<< endl;

}



