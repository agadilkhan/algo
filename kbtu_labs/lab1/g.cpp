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

    for(int i = 2; i <= 10000; i ++){
        if(isPrime(i)){
            v.push_back(i);
        }
    }
    cout << v[v[n - 1] - 1];
}