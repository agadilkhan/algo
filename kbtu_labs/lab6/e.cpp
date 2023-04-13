#include <iostream>

using namespace std;

int partition(int b[], int l, int h){
    int pivot = b[h];
    int i = l - 1;
    for(int j = l; j < h; j ++){
        if(b[j] > pivot){
            i ++;
            swap(b[i], b[j]);
        }
    }
    swap(b[i + 1], b[h]);
    return i + 1;
}

void qsort(int b[], int l, int h){
    if(l < h){
        int p = partition(b, l, h);
        qsort(b, l, p - 1);
        qsort(b, p + 1, h);
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    int a[n][m];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < m; i ++){
        int b[n];
        for(int j = 0; j < n; j ++){
            b[j] = a[j][i];
        }
        qsort(b, 0, n - 1);
        for(int k = 0; k < n; k ++){
            a[k][i] = b[k];
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cout << a[i][j] << ' ';
        }cout << endl;
    }
}