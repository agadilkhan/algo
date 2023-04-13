#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    int cnt = 0;
    for(int i = 0; i < n; i ++){
        int sum = 0;
        for(int j = i; j < n; j ++){
            sum += a[j];
            if(sum == 0) {
                cnt += (n-j);
                break;
            }
        }
    }
    cout << cnt;
}