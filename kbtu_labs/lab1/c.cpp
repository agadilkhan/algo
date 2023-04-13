#include <iostream>
#include <stack>
#include <string>


using namespace std;

int main(){

    string s, t;
    cin >> s >> t;

    stack<char> st1, st2;

    for(int i = 0; i < s.size(); i ++){
        if(s[i] != '#'){
            st1.push(s[i]);
        }
        else{
            st1.pop();
        }
    }

    for(int i = 0; i < t.size(); i ++){
        if(t[i] != '#'){
            st2.push(t[i]);
        }
        else{
            st2.pop();
        }
    }

    if(st1 == st2) cout << "Yes";
    else cout << "No";
}