#include <iostream>

using namespace std;

struct Heap
{
    int * a;
    int sz;
    Heap(){
        a = new int[200001];
        sz = 0;
    }
    int parent(int i){
        return i / 2;
    }
    int left(int i){
        return i * 2;
    }
    int right(int i){
        return i * 2 + 1;
    }
    int heap_up(int i){
        while(a[parent(i)] < a[i] and i > 1){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        return i;
    }
    void add(int val){
        sz ++;
        a[sz] = val;
        heap_up(sz);
    }
    void solve(int x, int y){
        a[x] += y;
        cout << heap_up(x) << endl;
    }
    void print(){
        for(int i = 1; i <= sz; i ++)
            cout << a[i] << ' ';
    }
};

int main(){

    int n;
    cin >> n;
    Heap hp;

    while(n --){
        int x;
        cin >> x;
        hp.add(x);
    }
    
    int k;
    cin >> k;

    while(k --){
        int x, y;
        cin >> x >> y;
        hp.solve(x, y);
    }
    hp.print();
}