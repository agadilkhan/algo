#include <iostream>

using namespace std;

int b_s(char c[], char t, int n){
    int l = 0, r = n - 1, mid;
    int idx = 0;
    while(l <= r){
        mid = (l + r) / 2;
        if(t == c[mid]){
            if(mid < n - 1) idx = mid + 1;
            else idx = 0;
            break;
        }
        else if(t > c[mid]){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    } 
    return idx;
}

int main(){

    int n;
    cin >> n;

    char c[n];
    for(int i = 0; i < n; i ++)
        cin >> c[i];
    
    char t;
    cin >> t;

    cout << c[b_s(c, t, n)];

}