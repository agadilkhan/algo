#include <bits/stdc++.h>

using namespace std;

vector<pair<string, size_t> > ans = {{"", 0}};

size_t f2(string s, string t){
    string str = t + s;
    str[0] = tolower(str[0]);
    str[t.size() + 1] = tolower(str[t.size() + 1]);
    for(size_t i = str.size() - 1; i >=1; --i){
        if(str.substr(0, i)  == str.substr(str.size() - i, i)){
            return i;
        }
        
    }
    return 0;
}


int main(){

    string s;
    cin >> s;

    int n;
    cin >> n;
    size_t m;

    while(n --){
        string t;
        cin >> t;
        m = f2(s, t);
        if(m > ans.back().second){
            ans.clear();
            ans.push_back({t, m});
        }
        else if(m == ans.back().second){
            ans.push_back({t, m});
        }
    }
    if(ans.back().second == 0) ans.clear();
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i.first << endl;
    }
}