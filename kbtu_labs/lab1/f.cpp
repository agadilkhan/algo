#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime(int n){
    for(int i = 2; i <= sqrt(n); i ++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    
    vector<int> v;
    int n;
    cin >> n;

    if(n == 1){
        cout << 2;
        return 0;
    }

    for(int i = 2; i <= n * n; i ++){
        if(isPrime(i)){
            v.push_back(i);
        }
    }
    cout << v[n - 1];
}