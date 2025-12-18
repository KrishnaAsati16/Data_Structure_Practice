#include<iostream>
#define Max 5
using namespace std;

struct Queue{
    int data[Max];
    int Front, Rare;
};

Queue *p, Q1;

void init(){
    p = &Q1;
    p->Front = p->Rare = -1;
}

int Full(){
    if(p->Rare==Max-1){
        cout << "Queue is Full " << endl;
        return 1;
    }else{
        return 0;
    }
}

int Empty(){
    if(p->Front==-1){
        cout << "Queue is Empty " << endl;
        return 1;
    }else{
        return 0;
    }
}

void EnQ(int x){
    if(Full()==1)
        return;
    if(p->Rare==-1){
        p->Front = p->Rare = 0;
    }else{
        p->Rare++;
    }
    p->data[p->Rare] = x;
}

int DeQ(){
    int x;
    if (Empty() == 1)
        return -1;
    x = p->data[p->Front];
    if(p->Front==p->Rare){
        p->Front = p->Rare = -1;
    }else{
        p->Front++;
    }
    return x;
}

int main(){
    init();
    EnQ(10);
    EnQ(20);
    EnQ(30);


    cout << DeQ() << endl;
    cout << DeQ() << endl;
    cout << DeQ() << endl;
}