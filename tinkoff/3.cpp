#include <iostream>
#include <set>
#include <limits.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    string s;
    cin >> s;

    int min_size = INT_MAX;
    bool ok = false;

    for(int i = 0; i < s.size(); i ++){
        set<char> st;
        for(int j = i; j < s.size(); j ++){
            st.insert(s[j]);
            if(st.size()==4){
                ok = true;
                int cur = j - i + 1;
                if(cur < min_size){
                    min_size = cur;
                    break;
                }
            }
        }
    }
    if(!ok) cout << -1 << endl;
    else cout << min_size << endl;
}