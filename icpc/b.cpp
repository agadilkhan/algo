#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    sort(a, a + n);
    for(int i = 0; i < n - 1; i ++) {
        if(a[i] == a[i + 1]) {
            a[i] = 0;
            a[i + 1] = 0;
        }
    }
    
    sort(a, a + n);
    int sum = 0;
    for(int i = 0; i < n - 1; i += 2) {
        sum += (a[i + 1] - a[i]);
    }

    cout << sum; 
}