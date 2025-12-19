// #include<iostream>
// #include<queue>

// using namespace std;


//     class CircularQueue{
//         int* arr;
//         int qfront;
//         int rear;
//         int size;

//         public:
//            CircularQueue(int n) {
//             size = 10001;
//             arr = new int[size];
//             qfront = rear =-1; 
//            }    

//             bool isempty(int value){
//                 if( qfront == 0 && rear == size-1) || (rear == (qfront-1)%(size-1))
//                 {
//                     cout<<"Queue is full"<< endl;
//                 }
//                 else
//                 {   
//                     if(qfront== -1){
//                     qfront = rear =0;
//                     arr[rear] = value;
//           }
//                  }
//                 else
//                 { 
//                 if( rear == size-1 && qfront !=0){
//                     rear =0; // to maintain cyclic nature
//          }
//                 }
//                 else
//                 {  // normal flow
//                     rear++;
                
//                 }
//                 // push inside the queue 
//                 arr[rear] = value;
//                 return true;    
//        }

//             int dequeue(){
//                 if( qfront == -1) // to check queue is empty
//                 {
//                     cout<< "Queue is empty" << endl;
//                     return -1;
//                 }
//                 int ans = arr[qfront];
//                 arr[qfront] =-1;
//                 if( qfront==rear) // single element is present
//                 {
//                     qfront = rear = -1;
//                 }
//                 else if(qfront == size-1)
//                 {
//                     qfront =0; //  top maintain cyclic nature
//                 }
//                 else 
//                 {
//                   qfront++;
//                 }
//                   return ans;
//         }
    
//     };




#include<iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int qfront;
    int rear;
    int size;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        qfront = rear = -1;
    }

    // enqueue
    bool enqueue(int value) {

        // queue full condition
        if ((qfront == 0 && rear == size - 1) ||
            (rear == (qfront - 1 + size) % size)) {
            cout << "Queue is full" << endl;
            return false;
        }

        // first element
        if (qfront == -1) {
            qfront = rear = 0;
            arr[rear] = value;
        }
        // rear at end but space at front
        else if (rear == size - 1 && qfront != 0) {
            rear = 0;
            arr[rear] = value;
        }
        // normal case
        else {
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    // dequeue
    int dequeue() {
        if (qfront == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;

        // single element
        if (qfront == rear) {
            qfront = rear = -1;
        }
        // front at end
        else if (qfront == size - 1) {
            qfront = 0;
        }
        // normal case
        else {
            qfront++;
        }

        return ans;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cout << cq.dequeue() << endl;
    cout << cq.dequeue() << endl;

    cq.enqueue(60);
    cq.enqueue(70);

    cout << cq.dequeue() << endl;

    return 0;
}