#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int leftcur = 0, rightcur = 0;

struct Node{
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
    //bool ok;
    Node * root;
    Node * insert(Node * cur, int val){
        if(!cur) return new Node(val);
        if(val > cur -> val) cur -> right = insert(cur -> right, val);
        if(val < cur -> val) cur -> left = insert(cur -> left, val);
        return cur;
    }
    Node * balanceTree(int a[], int l, int r){
        if(l > r) return nullptr; 
        int mid = (l + r) / 2;
        Node * cur = new Node(a[mid]);
        cur -> left = balanceTree(a, l, mid - 1);
        cur -> right = balanceTree(a, mid + 1, r);
        return cur;
    }
    int height(Node * cur){
        if(!cur) return 0;
        // if(abs(height(cur -> left) - height(cur -> right)) > 1){
        //     ok = false;
        // }
        return max(height(cur -> left), height(cur -> right)) + 1;
    }
   int lengthOfRightCur(Node * cur){
        if(cur == nullptr) return rightcur;
        rightcur += 1;
        lengthOfRightCur(cur->right);
    }

    int lengthOfLeftCur(Node * cur){
        if(cur == nullptr) return leftcur;
        leftcur += 1;
        lengthOfLeftCur(cur->left);
    }

    bool isBalanced(Node * cur, int rightlength, int leftlength){
        if(cur == nullptr){
            return true;
        }
        else{
            int lh = leftlength;
            int rh = rightlength;
            if(abs(lh - rh) > 1){
                return false;
            }
        }
        return true;
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
        //ok = true;
    }
    void insert(int val){
        root = insert(root, val);
    }
    void clear(){
        root = nullptr;
    }
    bool isBalanced(){
        lengthOfLeftCur(root);
        lengthOfRightCur(root);
        isBalanced(root, rightcur, leftcur);
    }
    void print(int a[], int l, int r){
        root = balanceTree(a, l, r);
        print(root);
    }
};

int main(){

    int n;
    cin >> n;
    int k = pow(2, n) - 1;

    BST tree;

    int a[k];
    for(int i = 0; i < k; i ++){
        cin >> a[i];
        tree.insert(a[i]);
    }

    //cout << tree.isBalanced();
    if(tree.isBalanced()){
        for(int i = 0; i < k; i ++)
            cout << a[i] << ' ';
    }else{
        tree.clear();
        sort(a, a + k);
        tree.print(a, 0, k - 1);
    }
}