#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    int cnt = 0;

    while(n --){
        int ok = 0;
        int a, b, c;
        cin >> a;
        if(a == 1) ok ++;
        cin >> b;
        if(b == 1) ok ++;
        cin >> c;
        if(c == 1) ok ++;
        if(ok >= 2) cnt ++;
    }

    cout << cnt;

}