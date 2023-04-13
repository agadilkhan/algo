#include <iostream>

using namespace std;

struct Node{
    int val;
    Node * next;
    Node(int val){
        this -> val = val;
        next = nullptr;
    }
};

struct LinkedList{

    Node * head;
    Node * tail;

    LinkedList(){
        head = tail = nullptr;
    }
    void push(int val){
        Node * newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    int nearestNum(int val){
        int min = 99999;
        Node * cur = head;
        int idx = -1;
        int res = 0;
        while(cur){
            idx ++;
            if(abs(val - cur -> val) < min){
                min = abs(val - cur -> val);
                res = idx;
            }
            cur = cur -> next;
        }
        return res;
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

    int x;
    cin >> x;

    cout << ll.nearestNum(x);

}