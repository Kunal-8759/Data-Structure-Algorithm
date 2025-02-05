#include<bits/stdc++.h>
using namespace std;


class Node{// node is created.
public:
    int val;
    Node *next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

class Stack{
    private:
    Node *top;
    int size;

    public:
    Stack(){
        top=NULL;
        size=0;
    }

    void push(int x){
        Node * temp=new Node(x);
        temp->next=top;
        top=temp;
        size++;
    }
    void pop(){
        Node* temp=top;
        top=top->next;
        delete(temp);
        size--;
    }
    int Top(){
        if(size==0){
            cout<<"underflow";
            return -1;
        }else{
            return top->val;
        }
    }
    int Size(){
        return size;
    }
};
int main(){
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