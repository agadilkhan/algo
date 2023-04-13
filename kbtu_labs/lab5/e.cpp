#include <iostream>
#include <limits.h>

using namespace std;

struct Heap
{
    long long * a;
    int sz;

    Heap(){
        a = new long long[200001];
        a[0] = LLONG_MIN;
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
    void insert(long long val){
        sz ++;
        a[sz] = val;
        heap_up(sz);        
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
            swap(a[i], a[min]);
            heap_down(min);
        }
    }
    long long extractMin(){
        long long res = a[1];
        swap(a[1], a[sz]);
        sz --;
        heap_down(1);
        return res;
    }
    void solve(){
        long long sum = 0;
        while(sz > 1){
            long long min1 = extractMin();
            long long min2 = extractMin();
            sum += min1 + min2;
            insert(min1 + min2);
        }
        cout << sum;
    }
    void print(){
        long long sum = 0;
        for(int i = 1; i <= sz; i ++){
            sum += a[i];
        }cout << sum << endl;
    }
};

int main(){

    Heap hp;

    int n, k;
    cin >> n >> k;

    while(n --){
        string s;
        cin >> s;
        if(s == "insert"){
            long long x;
            cin >> x;
            hp.insert(x);
            if(hp.sz > k){
                hp.extractMin();
            }
        }else if(s == "print"){
            hp.print();
        }
    }
}