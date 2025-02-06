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

class Queue{
    private:
    Node *start;
    Node* end;
    int size;

    public:
    Queue(){
        start=NULL;
        end=NULL;
        size=0;
    }

    void push(int x){
        Node * temp=new Node(x);
        if(size==0){
            start=end=temp;
            size++;
            return;
        }
        end->next=temp;
        end=temp;
        size++;
    }
    void pop(){
        if(size==0){
            cout<<"underflow";
            return;
        }
        else if(size==1){
            start=end=NULL;
            size--;
            return;
        }
        Node* temp=start;
        start=start->next;
        delete(temp);
        size--;
    }
    int front(){
        if(size==0){
            cout<<"underflow";
            return -1;
        }else{
            return start->val;
        }
    }
    int Size(){
        return size;
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
    cout<<q.Size();
  return 0;
}