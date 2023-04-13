#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    while(n --) {
        int x;
        cin >> x;

        int cnt = 0;

        int a[x];
        int sum = 0;
        for(int i = 0; i < x; i ++) {
            cin >> a[i];
            if(a[i] == 0) {
                cnt ++;
                a[i] ++;
            }
            sum += a[i];
        }

        if(sum == 0) cnt ++;
        cout << cnt << endl;
    }
}