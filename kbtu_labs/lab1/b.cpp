#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    vector<int> v(n);
    v[0] = -1;

    for(int i = 1; i < n; i ++){
        int j = i - 1;
        while(a[j] > a[i]){
            j --;
            if(j == -1){
                v[i] = -1;
                break;
            }
            
        }
        if(j != -1) v[i] = a[j]; 
    }

    for(int i = 0; i < v.size(); i ++){
        cout << v[i] << ' ';
    }
}