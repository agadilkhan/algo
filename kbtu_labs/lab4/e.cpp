#include <iostream>
#include <cmath>

using namespace std;

int maxi = 0;
int cnt = 0;

struct Node{
    int val;
    Node * left;
    Node * right;
    int level;
    Node(int val, int level){
        this -> val = val;
        right = left = nullptr;
        this -> level = level;
    }
};

class BST{
private:
    Node * root;
    void insert(Node * cur, int x, int y, int z, int level){
        if(!cur) return;
        if(cur -> val == x){
            if(z == 0) cur -> left = new Node(y, level + 1);
            if(z == 1) cur -> right = new Node(y, level + 1);
            return;
        }
        insert(cur -> left, x, y, z, level + 1);
        insert(cur -> right, x, y, z, level + 1);
    }
    int height(Node * cur){
        if(!cur) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;
    }
    void maxWidth(Node * cur, int level){
        if(!cur) return;
        if(cur -> level == level){
            cnt ++;
        }
        maxWidth(cur -> left, level);
        maxWidth(cur -> right, level);
    }
    void solve(Node * cur){
        int h = height(cur);
        for(int i = 1; i <= h; i ++){
            maxWidth(cur, i);
            if(cnt > maxi){
                maxi = cnt;
            }
            cnt = 0;
        }
        cout << maxi;
    }
    void print(Node * cur){
        if(!cur) return;
        print(cur -> left);
        cout << cur -> val << ' ' << cur -> level << endl;
        print(cur -> right);
    }
public:
    BST(){
        root = nullptr;
    }
    void insertOne(){
        root = new Node(1, 1);
    }
    void insert(int x, int y, int z){
        insert(root, x, y, z, 1);
    }
    void solve(){
        solve(root);
    }
    void print(){
        print(root);
    }
};

int main(){

    int n;
    cin >> n;
    n --;

    BST tree;
    tree.insertOne();

    while(n --){
        int x, y, z;
        cin >> x >> y >> z;
        tree.insert(x, y, z);
    }
    tree.solve();

}