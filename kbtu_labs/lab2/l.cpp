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
        Node * first = head;
        Node * second = head;
        int max = INT_MIN;
        while(first){
            second = first;
            int sum = 0;
            while(second){
                sum += second -> val;
                if(sum > max){
                    max = sum;
                }
                second = second -> next;
            }
            first = first -> next;
        }
        return max;
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