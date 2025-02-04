#include<iostream>
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

class LinkedList{
    public:
        Node *head;
        Node *tail;
        int size;

        LinkedList(){//default constructor
            head=NULL;
            tail=NULL;
            size=0;
        }

        void Insert_at_End(int);
        void Insert_at_Beginning(int);
        void Insert_at_Index(int ,int );
        void display();
        int get_at_idx(int);
        void Delete_at_Beginning();
        void Delete_at_End();
        void Delete_at_Index(int);
        
        
};

void LinkedList::Insert_at_Beginning(int val){
    Node *temp=new Node(val);
    if(size==0){
        head=tail=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
    size++;

}

void LinkedList:: Insert_at_End(int val){
        Node *temp=new Node(val);

        if(size==0){
            head=tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
}

void LinkedList:: Insert_at_Index(int idx ,int val){
    if(idx<0 || idx>size) {
        cout<<"inavalid index"<<endl;
    }
    else if(idx==0) Insert_at_Beginning(val);
    else if(idx==size) Insert_at_End(val);
    else{
        Node *temp=new Node(val);
        Node *ptr=head;
        for(int i=0;i<idx-1;i++){
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
        size++;
    }
}

void LinkedList::display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
}

int LinkedList::get_at_idx(int idx){
    if(idx<0 || idx>=size){
        cout<<"invalid index"<<endl;
    }
    else{
        Node *ptr=head;
        for(int i=0;i<idx;i++){
             ptr=ptr->next;
        }
        return ptr->val;
    }
}

void LinkedList:: Delete_at_Beginning(){
    if(size==0){
        cout<<"cant deleted"<<endl;
    }
    else if(size==1){
        head=tail=NULL;
        size--;
    }
    else{
        head=head->next;
        size--;
    }
}

void LinkedList::Delete_at_End(){
    if(size==0){
        cout<<"cant deleted"<<endl;
    }
    else if(size==1){
        head=tail=NULL;
        size--;
    }
    else{
        Node *temp=head;
        for(int i=0;i<size-2;i++){
            temp=temp->next;
        }
        tail=temp;
        temp->next=NULL;
        size--;
    }
}
void LinkedList::Delete_at_Index(int idx){
    
    if(idx<0 || idx>=size){
        cout<<"cant deleted";
    }
    else if(idx==0){
        Delete_at_Beginning();
    }
    else if(idx==size-1){
        Delete_at_End();
 
    }
    else{
        Node *temp=head;
        for(int i=0;i<idx-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        size--;
    }
}


int main(){
    LinkedList ll;
    ll.Insert_at_End(10);
    ll.Insert_at_End(45);
    ll.display();
    cout<<ll.size<<endl;
    ll.Insert_at_Beginning(11);
    ll.Insert_at_Beginning(22);
    ll.Insert_at_Beginning(33);
    ll.display();
    cout<<ll.size<<endl;
    ll.Insert_at_Index(2,57);
    ll.display();
    ll.Delete_at_Beginning();
    ll.display();
 
    ll.Delete_at_End();
    ll.display();  
    ll.Delete_at_Index(2);
    ll.display();  
}