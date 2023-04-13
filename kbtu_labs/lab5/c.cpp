#include <iostream>
#include <limits.h>

using namespace std;

struct Heap
{
    long long * a;
    int sz;

    Heap(){
        a = new long long[1000000];
        sz = 0;
        a[0] = LLONG_MAX;
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
        if(a[parent(i)] > a[i] or i < 1) return;
        swap(a[parent(i)], a[i]);
        heap_up(parent(i));
    }
    void heap_down(int i){
        int l = left(i);
        int r = right(i);
        int max = l;
        if(l > sz) return;
        if(r <= sz){
            if(a[r] > a[l]) max = r;
        }
        if(a[max] > a[i]){
            swap(a[max], a[i]);
            heap_down(max);
        }
    }
    void add(long long val){
        sz ++;
        a[sz] = val;
        heap_up(sz);
    }
    long long extractMax(){
        long long res = a[1];
        swap(a[1], a[sz]);
        sz --;
        heap_down(1);
        return res;
    }
    void print(){
        for(int i = 1; i <= sz; i ++){
            cout << a[i] << ' ';
        }
    }
    void solve(int k){
        long long sum = 0;
        while(k --){
            long long max = extractMax();
            sum += max;
            add(max - 1);
        }
        cout << sum;
    }
};

int main(){

    Heap hp;
    int n, k;
    cin >> n >> k;

    while(n --){
        long long x;
        cin >> x;
        hp.add(x);
    }
    hp.solve(k);
}