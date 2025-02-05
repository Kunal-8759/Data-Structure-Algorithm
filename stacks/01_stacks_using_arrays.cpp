#include<bits/stdc++.h>
using namespace std;

class Stack {
  int size;
  int * arr;
  int top;
  public:
    Stack() {
      top = -1;
      size = 1000;
      arr = new int[size];
    }
  void push(int x) {
    top++;
    arr[top] = x;
  }
  void pop() {
    if(top==-1){
        cout<<"cant be deleted";
        return;
    }
    top--;
  }
  int Top() {
    if(top==-1){
        cout<<"cant be fetched";
        return -1;
    }
    return arr[top];
  }
  int Size() {
    return top + 1;
  }
};
int main() {

  Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.Top()<<" ";
    st.pop();
    cout<<st.Top()<<" ";
    cout<<st.Size();
  return 0;
}