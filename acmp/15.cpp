#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n][n];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            if(a[i][j] == 1) cnt ++;
        }
    }

    cout << cnt / 2;
}