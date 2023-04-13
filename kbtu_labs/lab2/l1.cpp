#include <iostream>
#include <limits.h>

using namespace std;

struct Node
{
    int val;
    Node * next;

    Node(int val){
        this -> val = val;
        next = nullptr;
    }
};

struct LinkedList
{
    Node * head;
    Node * tail;

    LinkedList(){
        head = tail = nullptr;
    }
    void push(int val){
        Node * newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    int findMaxSum(){
        int max_so_far = INT_MIN;
        int max_end_here = 0;
        Node * cur = head;
        while(cur){
            max_end_here += cur -> val;
            if(max_so_far < max_end_here){
                max_so_far = max_end_here;
            }
            if(max_end_here < 0){
                max_end_here = 0;
            }
            cur = cur -> next;
        }
        return max_so_far;
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
    cout << ll.findMaxSum();

}