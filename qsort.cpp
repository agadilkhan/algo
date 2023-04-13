#include <iostream>

using namespace std;

int partition(int a[], int l, int h){
    int i = l - 1;
    int pivot = a[h];

    for(int j = l; j < h; j ++){
        if(a[j] < pivot){
            i ++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[h]);
    
    return i + 1;
}

void qsort(int a[], int l, int h){
    if(l < h){
        int p = partition(a, l, h);
        qsort(a, l, p - 1);
        qsort(a, p + 1, h);
    }
}
int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    qsort(a, 0, n - 1);
    for(int i = 0; i < n; i ++){
        cout << a[i] << ' ';
    }
}