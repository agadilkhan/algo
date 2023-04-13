#include <iostream>

using namespace std;

struct Node
{
    string val;
    Node * next;
    Node * prev;

    Node(string val){
        this -> val = val;
        next = prev = nullptr;
    }
};

struct LinkedList
{
    Node * head;
    Node * tail;

    LinkedList(){
        head = tail = nullptr;
    }
    void add_front(string val){
        cout << "ok" << endl;
        Node * newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        }else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }
    void add_back(string val){
        cout << "ok" << endl;
        Node * newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }
    void erase_front(){
        cout << head -> val << endl;
        if(!head -> next){
            head = tail = nullptr;
        }else{
            head = head -> next;
            head -> prev = nullptr;
        }
    }
    void erase_back(){
        cout << tail -> val << endl;
        if(!tail -> prev){
            tail = head = nullptr;
            // head = nullptr;
        }else{
            tail = tail -> prev;
            tail -> next = nullptr;
        }
    }
    void front(){
        cout << head -> val << endl;
    }
    void back(){
        cout << tail -> val << endl;
    }
    void clear(){
        cout << "ok" << endl;
        head = tail = nullptr;
    }
    void exit(){
        cout << "goodbye" << endl;
    }
};

int main(){

    LinkedList ll;

    string s;
    while(cin >> s){
        if(s == "add_front" or s == "add_back"){
            string t;
            cin >> t;
            if(s == "add_front"){
                ll.add_front(t);
            }else{
                ll.add_back(t);
            }
        }
        else if(s == "exit"){
            ll.exit();
            break;
        }
        else if(s == "clear"){
            ll.clear();
        }
        else{
            if(!ll.head){
                cout << "error" << endl;
            }
            else{
                if(s == "erase_front"){
                    ll.erase_front();
                }
                else if(s == "erase_back"){
                    ll.erase_back();
                }
                else if(s == "front"){
                    ll.front();
                }
                else if(s == "back"){
                    ll.back();
                }
            }
        }
    }

}