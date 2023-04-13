#include <iostream>
#include <stack>

using namespace std;

bool check(long long x){
    stack<int> st;
    bool ok = true;
    while(x > 0){
        int mod = x % 2;
        if(mod == 0) st.push(mod);
        else if(st.empty()){
            ok = false;
            break;
        }else if(mod == 1){
            if(st.top() == 0) st.pop();
        }
        x /= 2;
    }
    if(!st.empty() or !ok) return false;
    return true;
}

int main(){

    int n;
    cin >> n;

    while(n --){
        long long x;
        cin >> x;
        if(check(x)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}