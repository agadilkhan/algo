#include <iostream>

using namespace std;

struct Node
{
    string oldName, newName;
    Node * next;
    Node(string oldName, string newName){
        this -> oldName = oldName;
        this -> newName = newName;
        next = nullptr;
    }
};

struct LinkedList
{
    Node * head;
    int sz;
    LinkedList(){
        sz = 0;
        head = nullptr;
    }
    void push(string oldName, string newName){
        Node * newNode = new Node(oldName, newName);
        if(!head){
            sz ++;
            head = newNode;
        }else{
            Node * cur = head;
            while(cur){
                if(cur -> newName == newNode -> oldName){
                    cur -> newName = newNode -> newName;
                    break;
                }
                if(!cur -> next){
                    cur -> next = newNode;
                    sz ++;
                    break;
                }
                cur = cur -> next;
            }
        }
    }
    void sort(){
        Node * first = head;
        while(first){
            Node * second = first -> next;
            while(second){
                if(second -> oldName < first -> oldName){
                    swap(first -> oldName, second -> oldName);
                    swap(first -> newName, second -> newName);
                }
                second = second -> next;
            }
            first = first -> next;
        }
    }
    void print(){
        cout << sz << endl;
        Node * cur = head;
        while(cur){
            cout << cur -> oldName << ' ' << cur -> newName << endl;
            cur = cur -> next;
        }
    }
};

int main(){

    LinkedList ll; 
    int n;
    cin >> n;

    while(n --){
        string s, t;
        cin >> s >> t;
        ll.push(s, t);
    }
    ll.sort();
    ll.print();

}