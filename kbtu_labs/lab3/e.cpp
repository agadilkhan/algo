#include <iostream>

using namespace std;

int check(int max[], int x, int n){
    int cnt = 0;
    for(int i = 0; i < n; i ++){
        if(x >= max[i]) cnt ++;
    }
    return cnt;
}

int main(){

    int n, k;
    cin >> n >> k;

    int max[n]; 
    int l = 0, r = 0, m; 
    for(int i = 0; i < n; i ++){
        int maxi = 0;
        for(int j = 0; j < 4; j ++){
            int x;
            cin >> x;
            if(x > maxi) maxi = x;
            if(x > r) r = x;
        }
        max[i] = maxi;
    }

    while(l + 1 < r){
        m = (l + r) / 2;
        if(check(max, m, n) >= k){
            r = m;
        }else{
            l = m;
        }
    }
    cout << r;
}