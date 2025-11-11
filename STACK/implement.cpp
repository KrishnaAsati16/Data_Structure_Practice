#include<iostream>

 using namespace std;

class stack{  
    // FULL CLASS !!

      public :
        int * arr ;
        int top;   // TOP-> VARIABLE
        int size;

    // CONSTRUCTOR 

        stack (int size ){
            this -> size = size;
            arr = new int[size];
            top = -1;
        } 
         
        // FIRST FUNCTIO 

        void push(int element) {
           if(size - top > 1) {
            top ++;
            arr[top]= element;
           }
              else {
                cout << "space overflow" << endl; 
              }
        } 

        // SECOND FUNCTION 

        void pop (){
            if(top>=0){
                top-- ;
            }          
            else {
                cout << " stack is underflow"<< endl;
            }  
        }
        
        // THIRD FUNCTION 

        int peek (){
            if (top >=0 && top < size){
                 return arr[top];
            }
            else {
                cout << "stack is empty " << endl;
                return -1;
           }

        }

        // FOURTH FUNCTION 

        bool isEmpty (){
            if(top == -1){
                return true;
            }
              else {
                return false;
              }

        }


};
 int main () {

    stack st(5);
    
    st.push(22);
    st.push(43);
    st.push(44);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek () << endl; 




       // CREATION !!
       
       
        // stack<int> s;
         
        // // push operation 
        // s.push (2);
        // s.push (3);

        // // pop 
        //  s.pop();

        //  cout << "printing the top element" << s.top() << endl;
        //  if(s.empty()){
        //  cout << "Stack is empty " << endl;
        //  }
        //  else {
        //     cout << " stack is not empty" << endl; 
        //  }
        //  cout << "size of stack is " << s.size() << endl;
        //         return 0; 
        }

  
