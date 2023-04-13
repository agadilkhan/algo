#include <iostream>

using namespace std;

int cnt = 0;

struct Node
{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this -> val = val;
        left = right = nullptr;
    }
};

class BST
{
private:
    Node * root;
    Node * insert(Node * cur, int val){
        if(!cur) return new Node(val);
        if(val > cur -> val) cur -> right = insert(cur -> right, val);
        if(val < cur -> val) cur -> left = insert(cur -> left, val);
        return cur;
    }
    void solve(Node * cur){

    }
    void depth(Node * cur, int n, int l, int r){
        if(!cur) return;
        if(l == r and l == n){
            cnt ++;
        }
        depth(cur -> left, l + 1, r);
        depth(cur -> right, l, r + 1);
    }
public:
    BST(){
        root = nullptr;
    }
    void insert(int val){
        root = insert(root, val);
    }
};

int main(){

    int n;
    cin >> n;

    while(n --){
        int x;
        cin >> x;

    }

}