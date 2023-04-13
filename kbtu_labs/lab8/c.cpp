#include <bits/stdc++.h>

using namespace std;

set<int> st;

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
            int j = m;
            int k = i;
            while(j --){
                st.insert(k);
                k ++;
            }
        }
    }

}
int main(){

    string s;
    cin >> s;

    int n;
    cin >> n;

    while(n --){
        string t;
        cin >> t;
        f(s, t);
    }
    if(st.size() == s.size()) cout << "YES";
    else cout << "NO";
}