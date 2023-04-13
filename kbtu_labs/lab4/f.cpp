#include <iostream>

using namespace std;

int cnt = 0;

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
    int numOfTriangle(Node * cur){
        if(!cur) return cnt;
        if(cur -> left and cur -> right) cnt ++;
        numOfTriangle(cur -> left);
        numOfTriangle(cur -> right);
    }
public:
    BST(){
        root = nullptr;
    }
    void insert(int val){
        root = insert(root, val);
    }
    void numOfTriangle(){
        cout << numOfTriangle(root);
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
    tree.numOfTriangle();

}