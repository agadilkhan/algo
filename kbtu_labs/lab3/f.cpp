#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, a + n);

    int x;
    cin >> x;

    while(x --){

        int p;
        cin >> p;

        int l = 0, r = n - 1, m;

        while(l <= r){
            m = (l + r) / 2;
            if(p >= a[m]){
                break;
            }
            else if(a[m] > p){
                r = m - 1;
            }
        }

        while(p >= a[m]){
            m ++;
            if(m == n) break;
        }
        cout << m << ' ';

        int sum = 0;
        for(int i = 0; i < m; i ++){
            sum += a[i];
        }
        cout << sum << endl;
    }
}