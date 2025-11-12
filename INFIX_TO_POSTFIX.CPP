// #include<iostream>
// using namespace std;

// int prec(char c){

//     if(c=='^'){
//         return 3;
//     }  
//     else if(c=='*' || c=='/')
//     {
//         return 2;   
//     }
//     else if(c=='+' || c=='-'){
//         return 1;
//      }
//      else{
//               return -1;
//      }
//  string infixtopostfix (string st) {
//     stack<char> st;
//     for (int i=0; i<s.length();i++){
//         if((s[i]>='a' && s[i]<='z') ||   (s[i]>='a' && s[i]<='z') ){
//             res+=s[i];
//         }
//     else if(s[i]== '('){
//         st.push(s[i]);
//     }
//     else if(s[i]==')'){
//         st.push(s[i]);
//         while (!st.empty() && st.top()!='('){
//             res+=st.top();
//             st.pop();
//         }
//         if(!st.empty()){
//             st.pop();
//         }
//         else{
//               while (!st.empty() && prec(st.top()) > prec(s[i])){
//                 res+st.top();
//                 st.pop();
//               }
//               st.push(s[i]);
//         }
        
//     }

//     }
//  } 
//                 while(!st.empty()){
//                     res+st.top();
//                     st.pop();
//                 }
//                 return res;
 
//             }

//             int main(){
//                 cout<<  "enter your infix "<<endl;
//             }
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix to postfix
string infixToPostfix(string s) {
    stack<char> st;
    string res = "";

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If operand, add to result
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            res += c;

        // If '(', push to stack
        else if (c == '(')
            st.push(c);

        // If ')', pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }

        // If operator
        else {
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;

    cout << "Postfix expression: " << infixToPostfix(exp) << endl;
    return 0;
}
