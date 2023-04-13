#include <iostream>
#include <vector>

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
        if(str[i] == str[j]){
            v[i] = j + 1;
        }
    }
    return v;
}

int main(){

    string s;
    int n;
    cin >> s >> n;

    string t;
    cin >> t;

    string str = s + "#" + t;
    vector<size_t> v = kmp(str);
    int cnt = 0;
    for(size_t i = 0; i < v.size(); i ++){
        if(v[i] == s.size()){
            cnt ++;
        }
    }
    if(cnt >= n){
        cout << "YES";
    }else{
        cout << "NO";
    }
}