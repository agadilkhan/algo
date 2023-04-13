#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i <= n; i ++)
        a[i] = i;

    a[1] = 0;
    int i = 2;

    while(i <= n / 2){
        int j;
        if(a[i] != 0){
            j = i + i;
            while(j <= n){
                a[j] = 0;
                j += i;
            }
        }
        i ++;
    }

    vector<int> v;
    for(int i = 0; i < n; i ++){
        if(a[i] != 0) v.push_back(a[i]);
    }
    int cnt = 0;
    for(auto i : v){
        if(n % i == 0){
            cout << i << ' ';
            cnt ++;
        }
    }cout << endl;
    cout << cnt;
}