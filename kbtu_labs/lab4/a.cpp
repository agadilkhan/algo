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
    bool mountain(Node * cur, string s, int i, char c){
        if(!cur) return false;
        i ++;
        if(c == 'L') return mountain(cur -> left, s, i, s[i]);
        if(c == 'R') return mountain(cur -> right, s, i, s[i]);
        return true;
    }
    void print(Node * cur){
        if(!cur) return;
        print(cur -> left);
        cout << cur -> val << ' ';
        print(cur -> right);
    }
public: 
    BST(){
        root = nullptr;
    }
    void insert(int val){
        root = insert(root, val);
    }
    bool mountain(string s, int i, char c){
        return mountain(root, s, 0, s[0]);
    }
    void print(){
        print(root);
    }
};

int main(){

    BST tree;

    int n, x;
    cin >> n >> x;

    while(n --){
        int a;
        cin >> a;
        tree.insert(a);
    }

    while(x --){
        string s;
        cin >> s;
        if(tree.mountain(s, 0, s[0])) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}