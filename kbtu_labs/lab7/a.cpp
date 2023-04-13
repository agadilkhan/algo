#include <iostream>
#include <vector>

using namespace std;

void merge(vector<string> &v, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    string L[n1];
    for(int i = 0; i < n1; i ++){
        L[i] = v[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    string R[n2];
    for(int i = 0; i < n2; i ++){
        R[i] = v[l2 + i];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;
    while(i1 < n1 and i2 < n2){
        if(L[i1].size() > R[i2].size()){
            v[i] = R[i2];
            i2 ++;
        }else{
            v[i] = L[i1];
            i1 ++;
        }
        i ++;
    }
    for( ; i1 < n1; i1 ++){
        v[i] = L[i1];
        i ++;
    }
    for( ; i2 < n2; i2 ++){
        v[i] = R[i2];
        i ++;
    }
}

void msort(vector<string> &v, int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        msort(v, l, mid);
        msort(v, mid + 1, r);
        merge(v, l, mid, mid + 1, r);
    }
}

int main(){


    int n;
    cin >> n;
    n ++;

    for(int k = 0; k < n; k ++){
        vector<string> v;
        string t;
        getline(cin, t);
        int j = 0;
        if(k == 0) continue;
        string s = "";
        for(int i = 0; i < t.size(); i ++){
            if(t[i] != ' '){
                s += t[i];
            }else if(t[i] == ' '){
                v.push_back(s);
                s = "";
            }
            if(i == t.size() - 1) v.push_back(s);
        }
        msort(v, 0, v.size() - 1);

        for(int i = 0; i < v.size(); i ++)
            cout << v[i] << ' ';
        cout << endl;
    }

}