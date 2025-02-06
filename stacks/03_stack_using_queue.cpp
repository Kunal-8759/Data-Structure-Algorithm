#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
    queue<int> q;
    public:
    void push(int x){
        q.push(x);
        int size=q.size();
        if(size==1) return;
        for(int i=1;i<size;i++){
            q.push(q.front());
            q.pop();
        }
    }
    void pop(){
        q.pop();
    }
    int top(){
        return q.front();
    }
    int size(){
        return q.size();
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.top()<<" ";
    st.pop();
    cout<<st.top()<<" ";
    cout<<st.size();

}