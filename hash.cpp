#include <iostream>

using namespace std;

int main(){

    string s;
    cin >> s;

    int p = 5;
    int n = s.size();
    long long p_pow[n];
    p_pow[0] = 1;

    for(int i = 1; i < n; i ++){
        p_pow[i] = p_pow[i - 1] * p;
    }

    // for(int i = 0; i < s.size(); i ++){
    //     cout << p_pow[i] << ' ';
    // }

    string t;
    cin >> t;
    long long ht = 0;

    for(int i = 0; i < t.size(); i ++){
        ht += (t[i] - 'a' + 1) * p_pow[i];
    }
    
    long long h[n];
    for(int i = 0; i < n; i ++){
        h[i] = (s[i] - 'a' + 1) * p_pow[i];
        if(i > 0) h[i] += h[i - 1];
    }

    // for(int i = 0; i < n; i ++){
    //     cout << h[i] << ' ';
    // }

    for(int i = 0; i + t.size() - 1 < n; i ++){
        long long cur = h[i + t.size() - 1];
        if(i > 0) cur -= h[i - 1];
        if(ht * p_pow[i] == cur) cout << i << ' ';
    }
}