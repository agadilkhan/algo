#include <iostream>
#include <algorithm>

using namespace std;

int b_sL(int a[], int x, int n){
    int l = 0, r = n - 1;
    int m;
    while(l <= r){
        m = l + (r - l) / 2;
        if(a[m] == x){
            r = m - 1;
            break;
        }
        else if(a[m] > x){
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    return r + 1;
}

int b_sR(int a[], int x, int n){
    int l = 0, r = n - 1;
    int m;
    while(l <= r){
        m = l + (r - l) / 2;
        if(a[m] == x){
            l = m + 1;
            break;
        }
        else if(a[m] > x){
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    return n - l;
}

// int b_sL2(int a[], int x, int n){
//     int l = 0, int r = n - 1, m;
//     while(l <= r){
//         m = l + (r - l) / 2;
//         if(a[m] == x){
//             l = m;
//             break;
//         }
//         else if(a[m] < x){
//             l = m + 1;
//         }else{
//             r = m - 1;
//         }
//     }
// }

int main(){

    int n, x;
    cin >> n >> x;

    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, a + n);

    // for(int i = 0; i < n; i ++)
    //     cout << a[i] << ' ';

    // int x;
    // cin >> x;

    // cout << (b_sR(a, x, n));

    while(x --){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if(r1 >= l2 and l1 <= r2){
            int l, r;
            l = b_sL(a, min(l1, l2), n);
            r = b_sR(a, max(r1, r2), n);
            
            cout << n - (l + r) << endl;
        }
        else{
            l1 = b_sL(a, l1, n);
            r1 = b_sR(a, r1, n);
            l2 = b_sL(a, l2, n);
            r2 = b_sR(a, r2, n);

            cout << 2 * n - (l1 + r1 + l2 + r2) << endl;
        }
    }

}