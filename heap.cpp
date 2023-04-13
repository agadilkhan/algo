#include <iostream>

using namespace std;

struct Heap{
    int * a;
    int sz;

    Heap(){
        a = new int[100001];
        sz = 0;
    }
    void insert(int val){
        a[sz] = val;
        sz ++;
        heap_up(sz - 1);
    }
    int parent(int i){
        return (i - 1) / 2;
    }
    int left(int i){
        return i * 2 + 1;
    }
    int right(int i){
        return i * 2 + 2;
    }
    void heap_up(int i){
        while(i > 0 && a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }
    void heap_down(int i){
        int l = left(i);
        int r = right(i);
        int m = l;
        if(l >= sz) return;
        if(r < sz){
            if(a[l] < a[r]) m = r;
        }
        if(a[m] > a[i]){
            swap(a[m], a[i]);
            heap_down(m);
        }
    }
    int extractMax(){
        int res = a[0];
        sz --;
        swap(a[0], a[sz]);
        heap_down(0);
        return res;
    }
    void print(){
        for(int i = 0; i < sz; i ++){
            cout << a[i] << ' ';
        }
    }
};

int main(){

    int n;
    cin >> n;
    Heap hp;

    while(n --){
        int x;
        cin >> x;
        hp.insert(x);
    }
    cout << hp.extractMax() << endl;
    cout << hp.extractMax() << endl;
    cout << hp.extractMax() << endl;
    cout << hp.extractMax() << endl;
    cout << hp.extractMax() << endl;
}