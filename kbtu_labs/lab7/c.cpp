#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    int L[n1];
    for(int i = 0; i < n1; i ++){
        L[i] = a[i + l1];
    }

    int n2 = r2 - l2 + 1;
    int R[n2];
    for(int i = 0; i < n2; i ++){
        R[i] = a[i + l2];
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

void msort(vector<int> &a, int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        msort(a, l, mid);
        msort(a, mid + 1, r);
        merge(a, l, mid, mid + 1, r);
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    
    for(int i = 0; i < m; i ++)
        cin >> b[i];
    

    msort(a, 0, n - 1);
    msort(b, 0, m - 1);
    
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