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

    LinkedList(){
        head = nullptr;
    }
    
    void push(int val){
        Node * newNode = new Node(val);
        if(!head){
            head = newNode;
        }
        else{
            Node * cur = head;
            while(cur){
                if(!cur -> next){
                    cur -> next = newNode;
                    break;
                }
                cur = cur -> next;
            }
        }
    }
    void solve(){
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

    int idx = 0;
    while(n --){
        int x;
        cin >> x;
        if(idx % 2 ==0) ll.push(x);
        idx ++;
    }
    ll.solve();

}