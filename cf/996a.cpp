#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[] = {1, 5, 10, 20, 100};

    int l = 0, r = sizeof(a) / sizeof(a[0]) - 1, mid;
    int cnt = 0;

    while(l <= r){
        mid = (l + r) / 2;
        if(n == a[mid]){
            cnt ++;
            break;
        }
        else if(n > a[mid]){
            if(n < a[mid + 1] or l == r){
                cnt ++;
                n -= a[mid];
                l = 0;
            }
            else l = mid + 1;
        }else{
            if(n > a[mid - 1]){
                cnt ++;
                n -= a[mid - 1];
                r = sizeof(a) / sizeof(a[0]);
            }else{
                r = mid - 1;
            }
        }
    }

    cout << cnt;
}