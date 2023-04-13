#include <iostream>

using namespace std;

struct Node
{
    char val;
    bool ok;
    Node * next;

    Node(char val){
        this -> val = val;
        ok = true;
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
    void push(char val){
        Node * newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    void print(){
        Node * first = head -> next;
        Node * cur = head;
        Node * check = head;
        cout << cur -> val << ' ';
        while(first){
            while(check != first){
                if(first -> val == check -> val){
                    first -> ok = false;
                    check -> ok = false;
                }
                check = check -> next;
            }
            check = head;
            if(cur -> val == first -> val and !cur -> ok){
                while(cur != first){
                    cur = cur -> next;
                    if(cur -> ok) break;
                }
                if(cur == first){
                    cout << -1 << ' ';
                    cur = cur -> next;
                }else{
                    cout << cur -> val << ' ';
                }
            }else{
                cout << cur -> val << ' ';
            }
            first = first -> next;
        }
        cout << endl;
    }
};

int main(){

    int x;
    cin >> x;
    while(x --){
        LinkedList ll;

        int n;
        cin >> n;

        while(n --){
            char c;
            cin >> c;
            ll.push(c);
        }
        ll.print();
    }
}