#include <iostream>

using namespace std;

int cnt = 0;

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
    void heap_up(int i){
        while(a[parent(i)] < a[i] and i > 1){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }
    void add(int val){
        sz ++;
        a[sz] = val;
        heap_up(sz);
    }
    void checking(int i){
        if(right(i) <= sz){
            if(a[right(i)] > a[left(i)]) cnt ++;
            checking(right(i));
            checking(left(i));
        }
    }
    void solve(){
        checking(1);
        cout << cnt;
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
    hp.solve();
}
