#include <iostream>
#include <vector>

using namespace std;

bool check(int mid, vector<int> &l, vector<int> &r, int s){
    
}

int main(){

    int n, s;
    cin >> n >> s;

    vector<int> l(n), r(n);
    for(int i = 0; i < n; i ++){
        cin >> l[i] >> r[i];
    }

    int low=0, high=s;
    int ans = 0;
    while(low < high){
        int mid = (low+high) / 2;
        if(check(mid, l, r, s)) {
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout << ans;
}