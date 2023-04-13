#include <iostream>
#include <vector>

using namespace std;

vector<int> kmp(string str){
    vector<int> v(str.size());
    v[0] = 0;
    for(int i = 1; i < str.size(); i ++){
        int j = v[i - 1];
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

    string s;
    cin >> s;

    vector<int> v = kmp(s);

    cout << s.size() - v.back();
}