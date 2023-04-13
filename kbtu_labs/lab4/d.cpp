#include <iostream>
#include <vector>

using namespace std;

int sum = 0;

struct Node
{
    int val;
    Node * right;
    Node * left;
    int level;

    Node(int val, int level){
        this -> val = val;
        right = left = nullptr;
        this -> level = level;
    }
};

class BST
{
private:
    Node * root;

    int cnt = 0;
    Node * insert(Node * cur, int val){
        if(!cur){
            int level = cnt;
            cnt = 0;
            return new Node(val, level);
        }
        if(cur -> val < val){
            cnt ++;
            cur -> right = insert(cur -> right, val);
        }
        if(cur -> val > val){
            cnt ++;
            cur -> left = insert(cur ->left, val);
        }
        return cur;
    }
    int height(Node * cur){
        if(!cur) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;
    }
    void sameLevel(Node * cur, int level){
        if(!cur) return;
        if(level == cur -> level){
            sum += cur -> val;
            return;
        }
        sameLevel(cur -> left, level);
        sameLevel(cur -> right, level);
    }
    void print(Node * cur){
        int h = height(cur);
        for(int i = 0; i < h; i ++){
            sameLevel(cur, i);
            cout << sum << ' ';
            sum = 0;
        }
    }
public:
    BST(){
        root = nullptr;
    }
    void insert(int val){
        root = insert(root, val);
    }
    void print(){
        print(root);
    }
    void height(){
        cout << height(root) << endl;
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
    tree.height();
    tree.print();
}