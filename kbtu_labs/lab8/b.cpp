#include <bits/stdc++.h>
using namespace std;
unordered_map <size_t, size_t> mp;
size_t cnt = 0;
void f(string s, string t){
    size_t n = s.size();
    size_t m = t.size();
    long long h[n];
    long long p[n];
    long long q = 2147483647;
    p[0] = 1;
    for(size_t i = 1; i < max(n, m); ++i){
        p[i] = (p[i - 1] * 31) % q;
    }
    for(size_t i = 0; i < n; ++i){
        h[i] = ((s[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1])  % q;
        }
    }
    long long h_t = 0;
    for(size_t i = 0; i < m; ++i){
        h_t = (h_t + ((t[i] - int('a') + 1) * p[i]) % q) % q;
    }
    for(size_t i = 0; i + m - 1 < n; i++){
        long long cur = h[i + m - 1];
        if(i > 0){
            cur = (cur - h[i-1] + q) % q;
        }
        if(cur == (h_t * p[i]) % q){
            mp[i] ++;
            if(mp[i] > 1) cnt ++;
        }
    }
}
int main(){

    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    f(s1, t);
    f(s2, t);
    cout << cnt << endl;
    
    return 0;
}