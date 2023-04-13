#include <iostream>

using namespace std;

int check(int a[], int k, int n){
    int sum = 0;
    for(int i = 0; i < n; i ++){
        if(k > a[i]) sum += 1;
        else if(a[i] % k != 0){
            sum += a[i] / k + 1;
        }else{
            sum += a[i] / k;
        }
    }
    return sum;
}

int main(){

    int n, h;
    cin >> n >> h;

    int a[n];
    int max = -999999;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        if(a[i] > max) max = a[i];
    }

    int l = 0, r = max, m;
    while(l + 1 < r){
        m = (l + r) / 2;
        if(check(a, m, n) <= h){
            r = m;
        }
        else{
            l = m;
        }
    }
    cout << r;
}