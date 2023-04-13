#include <iostream>

using namespace std;

void f(string s, string t){
    size_t n = s.size();
    size_t m = t.size();
    long long p[n];
    long long q = (1 << 30) + 7;
    p[0] = 1;

    for(size_t i = 1; i < n; i ++){
        p[i] = (p[i - 1] * 31) % q;
    }

    long long h[n];
    for(size_t i = 0; i < n; i ++){
        h[i] = ((s[i] - 'a' + 1) * p[i]) % q;
        if(i > 0) h[i] = (h[i - 1] + h[i]) % q;
    }

    long long ht = 0;
    for(size_t i = 0; i < m; i ++){
        ht = (ht + ((t[i] - 'a' + 1) * p[i]) % q) % q;
    }

    for(size_t i = 0; m + i - 1 < n; i ++){
        long long cur = (h[m + i - 1]);
        if(i > 0) cur = (cur - h[i - 1]) % q;
        if((ht * p[i]) % q == cur){
            cout << i << ' ';
        }
    }
}

int main(){

    string s, t;
    cin >> s >> t;

    f(s, t);
}