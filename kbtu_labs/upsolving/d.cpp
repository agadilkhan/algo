#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;

    set<int> st;

    int i = 2;
    while(i <= n){
        if(n % i == 0){
            n /= i;
            st.insert(i);
        }else i ++;
    
    }
    cout << st.size();
    
}