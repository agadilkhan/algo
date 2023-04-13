#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        if(i == 0) a[i] = x;
        else{
            for(int j = 0; j < i; j ++){
                sum += abs(x - a[j]);
            }
            a[i] = x;
        }
    }
    cout << sum * 2;
}