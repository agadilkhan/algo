#include <iostream>

using namespace std;

int c[200001];

void mergeTwo(int a[], int b[], int l1, int r1, int l2, int r2){
    int k = 0;
    while(l1 < r1 and l2 < r2){
        if(a[l1] < b[l2]){
            c[k] = a[l1];
            l1 ++;
        }else{
            c[k] = b[l2];
            l2 ++;
        }
        k ++;
    }

    for( ; l1 < r1; l1 ++){
        c[k] = a[l1];
        k ++;
    }
    for( ; l2 < r2; l2 ++){
        c[k] = b[l2];
        k ++;
    }
}

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i ++)
        cin >> a[i];

    int m;
    cin >> m;

    int b[m];
    for(int i = 0; i < m; i ++)
        cin >> b[i];

    mergeTwo(a, b, 0, n, 0, m);

    for(int i = 0; i < n + m; i++)
        cout << c[i] << ' ';
}