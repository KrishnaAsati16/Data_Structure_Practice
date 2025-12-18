#include<iostream>
#include<queue>

using namespace std;
 
int main(){ 

    // create a queue
     queue<int>q;

        q.push(20);
        q .push(206);
        q .push(2);

         cout<<"front of queue is: "<< q.front()<< endl;
                
        cout << "size of queue is: " << q.size()<< endl;

        q.pop();
        q.pop();

        cout << "size of queue is: " << q.size()<< endl;

        if(q.empty()){
            cout<<"queue is empty: "<< endl;
         } else{
                cout<<"queue is not empty: "<< endl;
            }
        }
