#include<iostream>
using namespace std;

class Heap 
{
  public:
     int arr[100];
     int size =0;

     Heap()
     {
        arr[0] = -1;
        size = 0;
     }

     void insert(int val)
     {
        size = size+1;
        int idx = size;
        arr[idx] = val;

        while(idx >1)
        {
          int parent = idx/2;

          if(arr[parent] < arr[idx])
          {
            swap(arr[parent], arr[idx]);
            idx = parent;
          }
          else
          {
            return ;
          }
        }
     } 

         void print()
         {
            for(int i = 1; i<=size;i++)
            {
                cout << " ";
            } cout << endl;
         }
};

int main ()
{
     Heap h;

     h.insert(50);
       h.insert(55);
         h.insert(53);
           h.insert(52);
             h.insert(54);
             h.print();
}