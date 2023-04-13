#include <iostream>

using namespace std;

int main(){

    int n, x;
    cin >> n >> x;

    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    while(x --){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int cnt = 0;
        for(int i = 0; i < n; i ++){
            if((a[i] >= l1 and a[i] <= r1) or (a[i]>= l2 and a[i] <= r2)) cnt ++;
        }
        cout << cnt << endl;
    }

}