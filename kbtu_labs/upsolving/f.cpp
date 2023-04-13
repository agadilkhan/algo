#include <iostream>

using namespace std;

int sum = 0;

struct Node
{
    int val;
    Node * left;
    Node * right;
    int level;

    Node(int val, int level){
        this -> val = val;
        left = right = nullptr;
        this -> level = level;
    }
};

class BST
{
private:
    Node * root;
    Node * insert(Node * cur, int val, int level){
        if(!cur) return new Node(val, level);
        if(val > cur -> val) cur -> right = insert(cur -> right, val, level + 1);
        if(val < cur -> val) cur -> left = insert(cur -> left, val, level + 1);
        return cur;
    }
    void solve(Node * cur){
        if(!cur) return;
        sum += (cur -> val - cur -> level);
        solve(cur -> left);
        solve(cur -> right);
    }
public:
    BST(){
        root = nullptr;
    }
    void insert(int val){
        root = insert(root, val, 0);
    }
    void solve(){
        solve(root);
        cout << sum << endl;
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