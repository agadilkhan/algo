#include <iostream>
#include <vector>

using namespace std;

struct Almas
{
    long long sum = 0;
    vector<int> v;
    string s;
};

void merge(Almas a[], int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    Almas L[n1];
    for(int i = 0; i < n1; i ++){
        L[i] = a[i + l1];
    }

    int n2 = r2 - l2 + 1;
    Almas R[n2];
    for(int i = 0; i < n2; i ++){
        R[i] = a[i + l2];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;
    while(i1 < n1 and i2 < n2){
        if(L[i1].sum > R[i2].sum){
            a[i] = L[i1];
            i1 ++;
        }else if(L[i1].sum < R[i2].sum){
            a[i] = R[i2];
            i2 ++;
        }else if(L[i1].sum == R[i2].sum){
            bool ok;
            for(int j = 0; j < L[i1].v.size(); j ++){
                if(L[i1].v[j] < R[i2].v[j]){
                    ok = true;
                    break;
                }else if(L[i1].v[j] > R[i2].v[j]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                a[i] = L[i1];
                i1 ++;
            }else{
                a[i] = R[i2];
                i2 ++;
            }
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

void msort(Almas a[], int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        msort(a, l, mid);
        msort(a, mid + 1, r);
        merge(a, l, mid, mid + 1, r);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    Almas a[n];

    for(int i = 0; i < n; i ++){
        long long sum = 0;
        string s = "";
        for(int j = 0; j < m; j ++){
            int x;
            cin >> x;
            s += to_string(x) + ' ';
            a[i].v.push_back(x);
            sum += x;
        }
        a[i].sum = sum;
        a[i].s = s;
    }

    msort(a, 0, n - 1);

    int cnt = 0;
    for(auto i : a){
        cnt ++;
        cout << i.s << endl;
    }
}