#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){

    int n;
    cin >> n;

    map<char, int> mp;

    for(int i = 0; i < n; i ++){
        string s;
        cin >> s;
        set<char> st;
        for(int i = 0; i < s.size(); i ++){
            st.insert(s[i]);
        }
        for(auto i: st){
            mp[i] ++;
        }
    }
    
    int cnt = 0;
    for(auto i: mp){
        if(i.second == n) {
            cnt ++;
        }
    }
    cout << cnt;
}