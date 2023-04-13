#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i ++)
        cin >> a[i];

    int cnt = 0;
    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j ++){
            for(int k = j + 1; k < n; k ++){
                if(i < j and j < k and a[i] < a[j] and a[j] < a[k]){
                    cnt ++;
                    break;
                }   
            }
        }
    }
    cout << cnt;
}