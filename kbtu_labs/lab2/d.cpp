#include <iostream>

using namespace std;

struct Node{
    int val;
    int cnt;
    Node * next;
    Node(int val){
        this -> val = val;
        cnt = 1;
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
                if(cur -> val == val){
                    cur -> cnt ++;
                    break;
                }
                else{
                    if(!cur -> next){
                        cur -> next = newNode;
                        break;
                    }
                }
                cur = cur -> next;
            }
        }
    }
    void sort(){
        Node * first = head;
        Node * second = head;
        while(first){
            second = first -> next;
            while(second){
                if(first -> cnt < second -> cnt){
                    swap(first -> cnt, second -> cnt);
                    swap(first -> val, second -> val);
                }
                else if(first -> cnt == second -> cnt){
                    if(first -> val < second -> val){
                        swap(first -> cnt, second -> cnt);
                        swap(first -> val, second -> val);
                    }
                }
                second = second -> next;
            }
            first = first -> next;
        }
    }
    void solve(){
        Node * cur = head;
        int max = cur -> cnt;
        while(cur){
            if(cur -> cnt == max){
                cout << cur -> val << ' ';
            }
            else break;
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

    ll.sort();
    ll.solve();

}