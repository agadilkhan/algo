#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    while(n --) {
        long long a, b, k;
        cin >> a >> b >> k;

        long long odd = k / 2, even = k - odd;
        long long pos = a * even - b * odd;

        cout << pos << endl;
    }

}