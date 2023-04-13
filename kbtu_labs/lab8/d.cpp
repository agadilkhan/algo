#include <iostream>

using namespace std;

struct Data{
    string s;
    int cnt;
};

int f(string t, string s){
    size_t n = t.size();
    size_t m = s.size();

    long long h[n];
    long long p[n];
    long long q = (1 << 30) - 1;

    p[0] = 1;

    for(size_t i = 1; i < max(n, m); ++i){
        p[i] = (p[i - 1] * 31) % q;
    }

    for(size_t i = 0; i < n; ++i){
        h[i] = ((t[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1])  % q;
        }
    }
    long long h_s = 0;
    for(size_t i = 0; i < m; ++i){
        h_s = (h_s + ((s[i] - int('a') + 1) * p[i]) % q) % q;
    }

    int cnt = 0;
    for(size_t i = 0; i + m - 1 < n; i++){
        long long d = h[i + m - 1];
        if(i > 0){
            d = (d - h[i-1] + q) % q;
        }
        if( d == (h_s * p[i]) % q  && t.substr(i, m) == s){
            cnt ++;
        }
    }
    return cnt;
}

int main(){

    int n;
    while(cin >> n){
        if(n == 0) return 0;
        string s[n];
        for(int i = 0; i < n; i ++){
            cin >> s[i];
        }
        string t;
        cin >> t;
        Data d[n];
        int max = -999999;
        for(int i = 0; i < n; i ++){
            d[i].s = s[i];
            d[i].cnt = f(t, s[i]);
            if(d[i].cnt > max){
                max = d[i].cnt;
            }
        }
        cout << max << endl;
        for(int i = 0; i < n; i ++){
            if(d[i].cnt == max){
                cout << d[i].s << endl;
            }
        }
    }   

}