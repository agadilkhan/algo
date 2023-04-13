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
    Node * head;
    Node * tail;

    LinkedList(){
        head = tail = nullptr;
    }

    void push(string val){
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
    Node * cyclicShift(int k){
        Node * cur = head;
        while(k --){
            cur = cur -> next;
        }
        Node * res = cur;
        cur -> prev -> next = nullptr;
        cur -> prev = nullptr;
        while(cur -> next){
            cur = cur -> next;
        }
        cur -> next = head;
        return res;
    }
    void print(int k){
        Node * cur = cyclicShift(k);
        while(cur){
            cout << cur -> val << ' ';
            cur = cur -> next;
        }
    }

};

int main(){

    LinkedList ll;

    int n, k;
    cin >> n >> k;

    while(n --){
        string s;
        cin >> s;
        ll.push(s);
    }

    ll.print(k);

}