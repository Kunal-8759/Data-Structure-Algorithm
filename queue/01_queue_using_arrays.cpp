#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
    int capacity;//size of the array
    int start;
    int end;
    int * arr;
    int size;//size of the queue
    public:

    Queue(){
        capacity=1000;
        start=-1;
        end=-1;
        arr=new int[capacity];
        size=0;
    }
    void push(int x){
        if(size==capacity){
            cout<<"overflow";
            return;
        }
        else if(size==0){
            start=end=0;
        }
        else{
            end=(end+1)%capacity;
        }
        arr[end]=x;
        size++;
    }
    void pop(){
        if(size==0){
            cout<<"underflow";
            return;
        }
        else if(size==1){
            start=end=-1;
        }
        else{
            start=(start+1)%capacity;
        }
        size--;
    }
    int front(){
        if(size==0){
            cout<<"underflow";
            return -1;
        }
        else{
            return arr[start];
        }
    }
    int Size(){
        return size;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    cout<<q.Size();

}