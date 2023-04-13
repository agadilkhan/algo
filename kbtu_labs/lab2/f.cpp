#include <iostream>

using namespace std;

struct Node{
    
    int val;
    Node * next;
    Node * prev;

    Node(int val){
        this -> val = val;
        next = prev = nullptr;
    }
};

struct LinkedList{

    int size = 0;
    Node * head;
    Node * tail;

    LinkedList(){
        head = tail = nullptr;
    }

    void push(int val){
        size ++;
        Node * newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }
    void insert(int val, int pos){
        Node * newNode = new Node(val);
        if(pos == 0){
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
            return;
        }
        if(pos == size){
            tail -> next = newNode;
            newNode -> prev = tail;
            return;
        }
        Node * cur = head;
        int idx = 0;
        while(cur){
            if(idx == pos){
                newNode -> next = cur;
                newNode -> prev = cur -> prev;
                cur -> prev -> next = newNode;
                cur -> prev = newNode;
                break;
            }
            idx ++;
            cur = cur -> next;
        }
    }
    void print(){
        Node * cur = head;
        while(cur){
            cout << cur -> val << ' ';
            cur = cur -> next;
        }
    }
};

int main(){

    LinkedList ll;

    int n;
    cin >> n;

    while(n --){
        int x;
        cin >> x;
        ll.push(x);
    }
    
    int val, pos;
    cin >> val >> pos;

    ll.insert(val, pos);
    ll.print(); 

}