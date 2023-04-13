#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this -> val = val;
        next = nullptr;
        prev = nullptr;
    }
};

int temp;

class Deque{
    int sz;
    public:
    Node* head;
    Node* tail;
    Deque(){
        sz = 0;
        head = nullptr;
        tail = nullptr;
    }
    Node* findleft(int n){
        Node* cur = head;
        while(--n){
            cur = cur -> next;
        }
        return cur;
    }
    void insert(int val,int n){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
            sz++;
        }
        else{
            Node* need = findleft(n+1);
            if(!need){
                tail -> next = newNode;
                newNode -> prev = tail;
                tail = newNode;
                sz++;
            }
            else if (need -> prev){
                need -> prev -> next = newNode;
                newNode -> prev = need -> prev;
                newNode -> next = need;
                need -> prev = newNode;
                sz++;

            }
            else{
                newNode -> next = head;
                head -> prev = newNode;
                head = head -> prev;
                sz++;
            }
        }
    }
    void erase(int n,int &temp){
        Node* need = findleft(n+1);
    
        temp = need -> val;
        if(need -> prev && need -> next!= nullptr){ 
            need -> prev -> next = need -> next;
            need -> next -> prev = need -> prev;
            sz--;
        }
        else if(need -> prev == nullptr && need -> next == nullptr){ 
            head = tail = nullptr;
            sz--;
        }
        else if (need -> next == nullptr){ 
            need -> prev -> next = nullptr;
            tail = need -> prev;
            sz--;
        }
        else{   
            head = head -> next;
            head -> prev = nullptr;
            sz--;
        }
        
    }
    void replace(int p1,int p2){
        erase(p1,temp);   
        insert(temp,p2);   
    }
    void reverse(){
        Node* cur = head;
        Node* next = nullptr;
        Node* prev = nullptr;
        tail = cur;
        while(cur){
            next = cur -> next;
            cur -> prev = next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

void push_back(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = nullptr;
        }
        else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = tail -> next;
        }
    }
    void cycleleft(int k){
        int cnt=0;
        Node* cur = head;
        while(cur){
            if(cnt == k%size()){head = cur;return;}
            else{
                Node* newNode = new Node(cur->val);
                tail -> next = newNode;
                newNode -> prev = tail;
                tail = tail -> next;
                head = head -> next;
                head -> prev = nullptr;
            }
            cur = cur -> next;
            cnt++;
        }
    }
    void cycleright(int k){
        int cnt = 0;
        Node* cur = tail;
        while(cur){
            if(cnt == k%size()){tail = cur;return;}
            else{
                Node * newNode = new Node(cur -> val);
                head -> prev = newNode;
                newNode -> next = head;
                head = newNode;
                tail = tail -> prev;
                tail -> next = nullptr;
            }
            cur = cur -> prev;
            cnt++;
        }
    }
    int size(){
        return sz;
    }
    void print(){
        Node* cur = head;
        while(cur){
            cout<<cur -> val<<" ";
            cur = cur -> next;
        }
    }
};

int main(){
    Deque dq;
    while(true){
        int n;
        cin>>n;
        if(n==0){
            return 0;
        }
        else if(n==1){
            int x,p;
            cin>>x>>p;
            dq.insert(x,p);
        }
        else if(n==2){
            int p;
            cin>>p;
            dq.erase(p,temp);
        }
        else if(n==3){
            if(dq.size()!=0){
                dq.print();
            }else cout<<-1<<endl;
        }
        else if(n==4){
            int p1,p2;
            cin>>p1>>p2;
            dq.replace(p1,p2);
        }
        else if(n==5){
            dq.reverse();
        }
        else if(n==6){
            int x;
            cin>>x;
            dq.cycleleft(x);
        }
        else if(n==7){
            int x;
            cin>>x;
            dq.cycleright(x);
        }

        
    }
}