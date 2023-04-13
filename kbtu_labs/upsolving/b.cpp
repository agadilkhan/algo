#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[200001];
    for(int i = 0; i <= n; i ++)
        a[i] = i;

    a[1] = 0;
    int i = 2;

    while(i <= n){
        if(a[i] != 0){
            int j = i + i;
            while(j <= n){
                a[j] = 0;
                j += i;
            }
        }
        i ++;
    }

    vector<int> v;
    for(int i = 0; i <= n; i ++){
        if(a[i] != 0) v.push_back(a[i]);
    }

    for(int i = 0; i < v.size(); i ++){
        for(int j = 0; j < v.size(); j ++){
            if(v[i] + v[j] == n){
                cout << v[i] << ' ' << v[j] << endl;
                return 0;
            }
        }
    }
}