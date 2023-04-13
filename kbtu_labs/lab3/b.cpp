#include <iostream>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    int a[n];
    long long l = 0, r = 0, mid, ans;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        if(a[i] > l){
            l = a[i];
        }
        r += a[i];
    }

    while(l <= r){
        mid = (l + r) / 2;
        int cnt = 0;
        long long sum = 0;
        for(int i = 0; i < n; i ++){
            if(a[i] + sum <= mid) sum += a[i];
            else cnt ++, sum = a[i];
        }
        cnt ++;
        if(cnt <= m){
            r = mid - 1;
            ans = mid;
        }else{
            l = mid + 1;
        }
    }

    cout << ans;

}