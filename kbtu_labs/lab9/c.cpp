#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<size_t> kmp(string str){
    size_t n = str.size();
    vector<size_t> v(n);
    v[0] = 0;
    for(size_t i = 1; i < n; i ++){
        size_t j = v[i - 1];
        while(j > 0 and str[j] != str[i]){
            j = v[j - 1];
        }
        if(str[j] == str[i]){
            v[i] = j + 1;
        }
    }
    return v;
}

int main(){

    string s, t;
    cin >> s >> t;
    s += s;

    string str = t + "#" + s;

    vector<size_t> v = kmp(str);
    size_t ans = v.back();
    sort(v.begin(), v.end());
    if(v.back() != t.size()){
        cout << -1 << endl;
        return 0;
    }
    cout << ans;
    
}