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
        if(!cur) return;
        if(!cur -> left and !cur -> right){
            cnt ++;
            return;
        }
        solve(cur -> left);
        solve(cur -> right);
    }
public:
    BST(){
        root = nullptr;
    }
    void insert(int val){
        root = insert(root, val);
    }
    void solve(){
        solve(root);
        cout << cnt;
    }
};

int main(){

    int n;
    cin >> n;
    BST tree;

    while(n --){
        int x;
        cin >> x;
        tree.insert(x);
    }
    tree.solve();
}