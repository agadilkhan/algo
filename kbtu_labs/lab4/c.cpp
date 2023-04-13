#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node * right;
    Node * left;

    Node(int val){
        this -> val = val;
        right = left = nullptr;
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
    Node * subTree(Node * cur, int val){
        if(val > cur -> val) return subTree(cur -> right, val);
        if(val < cur -> val) return subTree(cur -> left, val);
        return cur;
    }
    void print(Node * cur){
        if(!cur) return;
        cout << cur -> val << ' ';
        print(cur -> left);
        print(cur -> right);
    }
public:
    BST(){
        root = nullptr;
    }
    void insert(int val){
        root = insert(root, val);
    }
    void subTree(int val){
        Node * sub = subTree(root, val);
        print(sub);
    }
};

int main(){

    BST tree;
    int n;
    cin >> n;

    while(n --){
        int x;
        cin >> x;
        tree.insert(x);
    }

    int a;
    cin >> a;

    tree.subTree(a);

}