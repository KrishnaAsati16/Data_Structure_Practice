// #include<iostream>

// using namespace std;
//  class Twostack {
//     int *arr;
//     int top1;
//     int top2;
//     int size;

//     public:
//         Twostack(int s)
//     {
//     this -> size = s;
//     top1 = -1;
//      top2 = s;
//      arr = new int[s];                   
//         }
//         void push1 (int num){
//             if(top2-top1 > 1){
//                 top1 ++;
//                 arr[top1]= num;
//             }
//             else {
//                   cout << "space overflow " << endl;
//             }
//         } 
//         void push2 (int num){
//           if(top2-top1 > 1){
//                 top2 -- ;
//                 arr[top2]= num;
//             }
//             else {
//                   cout << "space underflow " << endl;
//             }   
//         }

//          void pop1(){
//             if(top1 >=0){
//                 int ans = arr[top1];
//                 top1--;
//                 return ;
//             }
//             else {
//                 return ;
//             }
//          }

//          void pop2 (){
//             if(top1 < size){
//                 int ans = arr[top2];
//                 top2 ++;
//                 return ;
//             }
//             else {
//                 return ;
//             }
//          }
//     };

#include <iostream>
using namespace std;

class Twostack {
    int *arr;
    int top1;
    int top2;
    int size;

public:
    Twostack(int s) {
        size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int num) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        } else {
            cout << "Stack Overflow in Stack1" << endl;
        }
    }

    void push2(int num) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
        } else {
            cout << "Stack Overflow in Stack2" << endl;
        }
    }

    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            cout << "Stack Underflow in Stack1" << endl;
            return -1;
        }
    }

    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            cout << "Stack Underflow in Stack2" << endl;
            return -1;
        }
    }

    ~Twostack() {
        delete[] arr;
    }
};

int main() {
    Twostack ts(5);

    ts.push1(1);
    ts.push2(100);
    ts.push1(2);
    ts.push2(200);

    cout << "Pop from stack1: " << ts.pop1() << endl;
    cout << "Pop from stack2: " << ts.pop2() << endl;

    return 0;
}
