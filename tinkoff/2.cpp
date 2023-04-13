#include <iostream>

using namespace std;

int main() {
    
    int n, m, k;
    cin >> n >> m >> k;

    int p = n * k;
    int t = p / m;
    if(p % m != 0) t ++;

    cout << t << endl;

}