#include <iostream>

using namespace std;

void merge(int a[], int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    int L[n1];
    for(int i = 0; i < n1; i ++){
        L[i] = a[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    int R[n2];
    for(int i = 0; i < n2; i ++){
        R[i] = a[l2 + i];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;
    while(i1 < n1 and i2 < n2){
        if(L[i1] < R[i2]){
            a[i] = L[i1];
            i1 ++;
        }else{
            a[i] = R[i2];
            i2 ++;
        }
        i ++;
    }
    for( ; i1 < n1; i1 ++){
        a[i] = L[i1];
        i ++;
    }
    for( ; i2 < n2; i2 ++){
        a[i] = R[i2];
        i ++;
    }
}

void msort(int a[], int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        msort(a, l, mid);
        msort(a, mid + 1, r);
        merge(a, l, mid, mid + 1, r);
    }
}

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    msort(a, 0, n - 1);

    for(int i = 0; i < n; i ++)
        cout << a[i] << ' ';
}