#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    while(n --) {
        int m, k;
        cin >> m >> k;

        int b = k;
        char c = 'a';
        while(m --) {
            cout << char(c + k - 1);
            k --;
            if(k == 0) {
                k = b;
            }
        }
        cout << endl;
    }

}