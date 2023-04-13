#include <iostream>

using namespace std;

int partition(int a[], int l, int h){
    int pivot = a[h];
    int i = l - 1;
    for(int j = l; j < h; j ++){
        if(a[j] < pivot){
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
        qsort(a, p + 1, h);
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    int a[n];
    for(int i = 0; i < n; i ++)
        cin >> a[i];

    int b[m];
    for(int i = 0; i < m; i ++)
        cin >> b[i];

    qsort(a, 0, n - 1);
    qsort(b, 0, m - 1);

    if(n > m){
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(b[i] == a[j]){
                    cout << b[i] << ' ';
                    a[j] = -1;
                    break;
                }
            }
        }
    }else{
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(a[i] == b[j]){
                    cout << a[i] << ' ';
                    b[j] = -1;
                    break;
                }
            }
        }
    }

}