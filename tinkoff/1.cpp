#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> v(4);
    vector<int> w;
    for(int i = 0; i < 4; i ++){
        cin >> v[i];
        w.push_back(v[i]);
    }

    sort(v.begin(), v.end());
    if(v == w){
        cout << "YES" << endl;
        return 0;
    }
    reverse(v.begin(), v.end());
    if(v == w){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
}