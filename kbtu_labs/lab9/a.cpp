#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<size_t> f(string str){
    size_t n = str.size();
    vector<size_t> v(n);
    v[0] = 0;
    for(size_t i = 1; i < n; ++i){
        size_t j = v[i - 1];
        while(j > 0 && str[j] != str[i]){
            j = v[j-1];
        }
        if(str[i] == str[j]){
            v[i] = j + 1;
        }
    }
    return v;
}

int main(){

    string s, t;
    cin >> s >> t;
    unordered_set<char> st1, st2;
    for(size_t i = 0; i < s.size(); i ++){
        st1.insert(s[i]);
    }
    for(size_t i = 0; i < t.size(); i ++){
        st2.insert(t[i]);
    }

    if(st1.size() != st2.size()){
        cout << -1 << endl;
        return 0;
    }

    bool ok = false;
    string l = s;
    long long cnt = 0;
    if(t.size() > 90000){
        cout << -1 << endl;
        return 0;
    }
    if(t.size() > 20000){
        cout << t.size() / s.size() + 1;
        return 0;
    }
    while(true){
        string str = t + '#'  + s;
        vector<size_t> v = f(str);
        cnt ++;
        for(size_t i = 0; i < v.size(); ++i){
            if(v[i] == t.size()){
                cout << cnt << endl;
                return 0;
            }
        }
        if(s.size() > t.size() + l.size() and !ok){
            cout << -1 << endl;
            return 0;
        }
        s += l;
    }
    return 0;
}