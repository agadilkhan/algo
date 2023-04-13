#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    while(n --) {
        int h, m;
        cin >> h >> m;
        int t = h * 60 + m;

        cout << 1440 - t << endl;
    }

}