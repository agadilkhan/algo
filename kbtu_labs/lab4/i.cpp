#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node * right;
    Node * left;
    int cnt;

    Node(int val){
        this -> val = val;
        right = left = nullptr;
        cnt = 1;
    }
};

class BST
{
private:
    Node * root;
    Node * insert(Node * cur, int val){
        if(!cur) return new Node(val);
        if(val == cur -> val) cur -> cnt ++;
        if(val > cur -> val) cur -> right = insert(cur -> right, val);
        if(val < cur -> val) cur -> left = insert(cur -> left, val);
        return cur;
    }
    void del(Node * cur, int val){
        if(!cur) return;
        if(val == cur -> val){
            cur -> cnt --;
            return;
        }
        del(cur -> left, val);
        del(cur -> right, val);
    }
    bool check(Node * cur, int val){
        if(!cur) return false;
        if(val > cur -> val) return check(cur -> right, val);
        if(val < cur -> val) return check(cur -> left, val);
        return true;
    }
    void print(Node * cur, int val){
        if(!cur) return;
        if(cur -> val == val){
            cout << cur -> cnt << endl;
            return;
        }
        print(cur -> left, val);
        print(cur -> right, val);
    }
public:
    BST(){
        root = nullptr;
    }
    void insert(int val){
        root = insert(root, val);
    }
    void del(int val){
        del(root, val);
    }
    void print(int val){
        if(check(root, val)){
            print(root, val);
        }
        else cout << 0 << endl;
    }
};

int main(){

    int n;
    cin >> n;

    BST tree;
    
    while(n --){
        string s;
        cin >> s;
        int x;
        cin >> x;
        if(s == "insert"){
            tree.insert(x);
        }
        else if(s == "delete"){
            tree.del(x);
        }
        else if(s == "cnt"){
            tree.print(x);
        }
    }
}