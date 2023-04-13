#include <bits/stdc++.h>

using namespace std;

int rightLength= 0;
int leftLength= 0;

struct Node{
    int val;
    int level;
    Node * left;
    Node * right;
    Node(int val, int level){
        this -> level = level;
        this -> val =val;
        right = left = nullptr;
    }
};
class BST{
private:
    Node * root;

    Node * insert(Node * cur, int val, int cnt){
        if(cur == nullptr){
            int level = cnt;
            return new Node(val, level);
        }
        if(cur->val < val) cur->left = insert(cur->left, val, cnt + 1);
        if(cur->val > val) cur->right = insert(cur->right, val, cnt + 1);
        return cur;
    }

    int distance = 0;

    int length(Node * cur){
        if(cur == nullptr){
            return distance;
        }

        leftLength = height(cur->left);
        rightLength = height(cur->right);

        int len = leftLength + rightLength + 1;
        if(distance < len){
            distance = len;
        }

        length(cur->left);
        length(cur->right);
    }

    int height(Node * cur){
        if(cur == nullptr) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;
    }

    Node * print(Node * cur){
        if(cur != nullptr){
            cout << cur->val << " " << cur->level << endl;
            print(cur->left);
            print(cur->right);
        }
    }
public:
    BST(){
        root = nullptr;
    }

    void insert(int val){
        root = insert(root, val, 0);
    }

    void length(){
        cout << length(root);
    }

    int height(){
        return height(root);
    }

    void print(){
        print(root);
    }
};

int main(){
    BST tree;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.insert(x);
    }
    tree.length();
}
