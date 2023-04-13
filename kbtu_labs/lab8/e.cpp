#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    long long p[n];
    p[0] = 1;
    for(int i = 1; i < n; i ++){
        p[i] = p[i - 1] * 2;
    }

    long long y;
    for(int i = 0; i < n; i ++){
        long long x;
        cin >> x;
        long long z = x;
        if(i > 0){
            x -= y;
        }
        x /= p[i];
        x += 97;
        cout << char(x);
        y = z;
    }

}