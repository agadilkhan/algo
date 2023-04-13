#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i ++)
        cin >> a[i];

    int x;
    cin >> x;

    int l = 0, r = n - 1, mid;  // 1 2 3 4 5 
    int idx = -1;
    
    while(l <= r){
        mid = (l + r) / 2;
        if(x == a[mid]){
            idx = mid;
            break;
        }
        else if(x > a[mid]){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << idx;
}