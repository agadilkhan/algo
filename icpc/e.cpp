#include <iostream>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    char c[k];
    for(int i = 0; i < k; i ++) {
        cin >> c[i];
    }

    long long cnt = 0;
    long long sum = 0;

    for(int i = 0; i < s.size(); i ++) {
        bool ok = false;
        for(int j = 0; j < k; j ++) {
            if(s[i] == c[j]) {
                ok = true;
                break;
            }
        }
        if(ok) cnt ++;
        if(!ok || (i == s.size() - 1 && ok)){
            sum += (cnt * (cnt + 1)) / 2;
            cnt = 0;
        }
    }

    cout << sum;
}