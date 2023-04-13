#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

vector<size_t> kmp(string s, string t){
    string str = t + "#" + s;
    size_t n = str.size();
    vector<size_t> v(n);
    v[0] = 0;
    for(size_t i = 1; i < n; i ++){
        size_t j = v[i - 1];
        while(j > 0 and str[i] != str[j]){
            j = v[j - 1];
        }
        if(str[j] == str[i]){
            v[i] = j + 1;
        }
        if(v[i] == t.size()){
            cnt ++;
        }
    }
    return v;
}

int main(){

    string s, t;
    cin >> s >> t;

    vector<size_t> v = kmp(s, t);

    cout << cnt << endl;
    for(int i = t.size() + 1; i < v.size(); i ++){
        if(v[i] == t.size()){
            cout << i - 2 * t.size() + 1 << ' ';
        }
    }

}