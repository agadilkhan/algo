#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    int x;
    cin >> x;

    int a[n];
    for(int i = 0; i < n; i ++){
        int b;
        cin >> b;
        if(i == 0){
            a[i] = b;
        }
        else a[i] = a[i - 1] + b;
    }
    
    while(x --){
        int p;
        cin >> p;
        int l = 0, r = n - 1, m;
        while(l <= r){
            m = l + (r - l) / 2;
            if(p == a[m]){
                break;
            }
            else if(p > a[m]){
                l = m + 1;
            }
            else if(p < a[m]){
                r = m - 1;
            }
            if(l - r == 1){
                m = l;
                break;
            }
        }
        cout << m + 1 << endl;
    }
}
