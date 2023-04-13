#include <iostream>

using namespace std;

struct Node{
    string val;
    Node * next;
    Node * prev;

    Node(string val){
        this -> val = val;
        next = prev = nullptr;
    }
};

struct LinkedList{
    int size = 1;
    Node * head;
    Node * tail;
    LinkedList(){
        head = tail = nullptr;
    }

    void push(string val){
        if(val == "") return;
        Node * newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        }
        else{
            if(val == tail -> val) return;
            size ++;
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }
    void print(){
        cout << "All in all: " << size << endl;
        cout << "Students:" << endl;
        Node * cur = tail;
        while(cur){
            cout << cur -> val << endl;
            cur = cur -> prev;
        }
    }
};

int main(){

    LinkedList ll;

    int n;
    cin >> n;

    while(n --){
        string s;
        cin >> s;
        ll.push(s);
    }
    ll.print();

}