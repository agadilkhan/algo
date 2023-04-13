#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i ++)
        cin >> a[i];

    int m;
    cin >> m;

    int b[m];
    for(int j = 0; j < m; j ++)
        cin >> b[j];


    int sum = 0;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            sum = (sum | (a[i] & b[j]));
        }
    }
    cout << sum;
}