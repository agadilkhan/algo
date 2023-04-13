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
        a[0] = LLONG_MIN;
    }
    long long parent(int i){
        return i / 2;
    }
    long long left(int i){
        return i * 2;
    }
    long long right(int i){
        return i * 2 + 1;
    }
    void heap_up(int i){
        if(a[parent(i)] < a[i] or i < 1) return;
        swap(a[parent(i)], a[i]);
        heap_up(parent(i));
    }
    void heap_down(int i){
        int l = left(i);
        int r = right(i);
        int min = l;
        if(l > sz) return;
        if(r <= sz){
            if(a[r] < a[l]) min = r;
        }
        if(a[min] < a[i]){
            swap(a[min], a[i]);
            heap_down(min);
        }
    }
    void add(long long val){
        sz ++;
        a[sz] = val;
        heap_up(sz);
    }
    long long extractMin(){
        long long res = a[1];
        swap(a[1], a[sz]);
        sz --;
        heap_down(1);
        return res;
    }
    void solve(int k){
        long long cnt = 0;
        long long min1;
        long long min2;
        while(sz > 1){
            min1 = extractMin();
            min2 = extractMin();
            if(min1 < k){
                cnt ++;
            }else{
                break;
            }
            add(min1 + 2 * min2);
        }
        if(min1 < k){
            cout << -1;
        }else{
            cout << cnt;
        }
    }
    void print(){
        for(int i = 1; i <= sz; i ++)
            cout << a[i] << ' ';
        cout << endl;
    }
};

int main(){

    int n, k;
    cin >> n >> k;

    Heap hp;

    while(n --){
        long long x;
        cin >> x;
        hp.add(x);
    }
    hp.solve(k);

}