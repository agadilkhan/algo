#include <iostream>

using namespace std;

int size = 0;

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
    void subTree(Node * cur, int val){
        if(val == cur -> val){
            getSize(cur);
        }
        if(val > cur -> val) subTree(cur -> right, val);
        if(val < cur -> val) subTree(cur -> left, val);
    }
    void getSize(Node * cur){
        if(!cur) return;
        size ++;
        getSize(cur -> left);
        getSize(cur -> right); 
    }
public:
    BST(){
        root = nullptr;
    }
    void insert(int val){
        root = insert(root, val);
    }
    void subTree(int val){
        subTree(root, val);
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

    cout << size;

}