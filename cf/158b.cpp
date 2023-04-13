#include <iostream>
#include <vector>
#include <algorithm>

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
    Node * head;
    Node * tail;
    LinkedList(){
        head = tail = nullptr;
    }

    void insert(int val){
        Node * newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        }else{
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
        }
    }
    void del(int val){
        if(val == head -> val){
            head = head -> next;
            head -> prev -> next = nullptr;
            head -> prev = nullptr;
        }else{
            Node * cur = head;
            while(cur -> next){
                if(cur -> val == val){
                    cur -> prev -> next = cur -> next;
                    cur -> next -> prev = cur -> prev;
                    delete cur;
                    return;
                }
                cur = cur -> next;
            }
            if(val == cur -> val){
                cur -> prev -> next = nullptr;
                delete cur;
                return;
            }
        }
    }
    void print(){
        Node * cur = head;
        while(cur){
            cout << cur -> val << ' ';
            cur = cur -> next;
        }
        cout << endl;
    }
};
int main(){

    int n;
    cin >> n;
    LinkedList ll;

    while(n --){
        int x;
        cin >> x;
        ll.insert(x);
    }
    Node * first = ll.head;
    Node * second = ll.head;
    //ll.print();
    while (first -> next)
    {
        second = first -> next;
        while(second){
            if(first -> val + second -> val == 4){
                cout << first -> val << ' ' << second -> val << endl; 
                ll.del(first -> val);
                ll.del(second -> val);
                ll.insert(4);
                ll.print();
                break;
            }
            second = second -> next;
        }
        first = first -> next;
    }
    cout << 1 ;
    first = ll.head;
    second = ll.head;
    while (first -> next)
    {
        second = first -> next;
        while(second){
            if(first -> val + second -> val < 4){
                ll.del(first -> val);
                ll.del(second -> val);
                ll.insert(first -> val + second -> val);
                break;
            }
            second = second -> next;
        }
        first = first -> next;
    }
    int sz = 0;
    Node * cur = ll.head;
    while(cur){
        cur = cur -> next;
        sz ++;
    }
    cout << sz;
}