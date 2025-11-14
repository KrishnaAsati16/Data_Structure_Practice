// #include <iostream>
// #include<stack>
// #include <cmath> 

//  using namespace std;
 
//  // POSTFIXEVALUTION FUNCTION
//   int postfixEvalution (string s){

//   stack<int> st;
   
//    for (int i=0; i<s.length(); i++){

//     if (s[i]>='0' && s[i]<=9){        // 0to9 means operent 
//          st.push(s[i]- '0');      // only integer value
//     }   
//     else {
//         int op2=st.top();      // operator nikal liya string me se 
//           st.pop();
//         int op1=st.top();
//          st.pop();
         
//          switch (s[i])
//          {
//          case '+':
//             st.push(op1 + op2);
//             break;

//          case '-':
//             st.push(op1 - op2);
//             break;

//          case '*':
//             st.push(op1 * op2);
//             break;

//          case '/':
//             st.push(op1 / op2);
//             break;

//             case '^':
//             st.push(pow(op1 ,op2));
//             break;
//          }

//     }

//    }

//    return st.top();
//   }

//   int main(){
//     cout<<postfixEvalution("537*+45/-")<< endl;
//     return 0;
//   }

#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int postfixEvaluation(string s) {
    stack<int> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {     // 0to9 means operent 
            st.push(s[i] - '0');     // only integer value
        } else {
            int op2 = st.top();  // operator nikal liya string me se 
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i]) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '^':
                    st.push(pow(op1, op2));
                    break;
            }
        }
    }

    return st.top();
}

int main() {
    cout << postfixEvaluation("537*+45/-");
    return 0;
}
