#include <bits/stdc++.h>

using namespace std;

vector<size_t> kmp(string str){
    size_t n = str.size();
    vector<size_t> v(n);
    v[0] = 0;
    for(size_t i = 1; i < n; i ++){
        size_t j = v[i - 1];
        if(j > 0 and str[j] != str[i]){
            j = v[j - 1];
        }
        if(str[j] == str[i]){
            v[i] = j + 1;
        }
    }
    return v;
}

int main(){

    int n;
    cin >> n;
    while(n --){
        string s;
        cin >> s;
        int k;
        cin >> k;
        vector<size_t> v = kmp(s);
        cout << (s.size() - v.back()) * k + v.back() << endl;
    }
}