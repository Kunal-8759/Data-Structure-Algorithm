#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
    stack<int> st;

    public :
    void push(int val){//push at bottom
        if(st.size()==0){//base case
            st.push(val);
            return;
        }
        int x=st.top();
        st.pop();
        push(val);//call
        st.push(x);//kaam
    }
    void pop(){
        if(st.size()==0){
            cout<<"underflow";
            return;
        }
        st.pop();
    }
    int front(){
        if(st.size()==0){
            cout<<"underflow";
            return -1;
        }
        return st.top();
    }
    int size(){
        return st.size();
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(30);
    q.push(40);
    q.push(20);
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    cout<<q.size();
  return 0;
}