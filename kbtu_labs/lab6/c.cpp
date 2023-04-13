#include <iostream>
#include <limits.h>
#include <cmath>
#include <map>

using namespace std;

int min_ = 999999;

int partition(int a[], int l, int h){
    int pivot = a[h];
    int i = l - 1;
    for(int j = l; j < h; j ++){
        if(a[j] < pivot){
            if(abs(a[j] - pivot) < min_){
                min_ = abs(a[j] - pivot);
            }
            i ++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[h]);
    return i + 1;
}

void qsort(int a[], int l, int h){
    if(l < h){
        int p = partition(a, l, h);
        qsort(a, l, p - 1);
        qsort(a, p, h);
    }
}

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i ++)
        cin >> a[i];

    qsort(a, 0, n - 1);

    for(int i = 0; i < n; i ++){
        if(abs(a[i] - a[i + 1]) == min_){
            cout << a[i] << ' ' << a[i + 1] << ' ';
        }
    }
}