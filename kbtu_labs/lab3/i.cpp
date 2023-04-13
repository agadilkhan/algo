#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    int x;
    cin >> x;

    int l = 0, r = n - 1;
    bool ok = false;
    while(l <= r){
        int m = (l + r) / 2;
        if(x == a[m]){
            ok = true;
            break;
        }
        else if(x > a[m]){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    
    if(ok) cout << "Yes";
    else cout << "No";
}