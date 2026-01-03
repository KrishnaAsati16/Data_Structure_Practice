#include<bits/stdc++.h>
using namespace std;

void bubble_sort (int arr[], int n)
{
    for(int i =n-1;i>=0;i--)
    {
        int didswp = 0;
        for(int j = 0; j<=i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                didswp =1;
            }
        }
        if(didswp ==0)
        {
            break;
        }   
    }
}   

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int choice;
    cout << "\n1. Sort array\n2. Exit\nEnter option: ";
    cin >> choice;

    if(choice == 1)
    {
        bubble_sort(arr, n);
        cout << "Sorted array: ";
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
    else
    {
        cout << "Exit";
    }

    return 0;
}

// time complixity -> o(n)