#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    int a[m];
    for(int i = 0; i < m; i ++)
        cin >> a[i];

    sort(a, a + m);

    for(int i = 0; i < m; i ++){
        int l = i + 1, r = m - 1, mid;
        while(l <= r){
            mid = (l + r) / 2;
            if(a[i] + a[mid] == n){
                cout << a[i] << ' ' << a[mid] << endl;
                return 0;
            }
            else if(a[i] + a[mid] > n){
                r = mid - 1;
            }else if(a[i] + a[mid] < n){
                l = mid + 1;
            }
        }
    }
}