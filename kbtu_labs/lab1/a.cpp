#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<vector<int> > v;

    while(n --){
        deque<int> d;
        vector<int> w;
        int x;
        cin >> x;
        d.push_back(x);
        x --;
        while(x != 0){
            d.push_front(x);
            int y = x;
            while(y --){
                d.push_front(d.back());
                d.pop_back();
            }
            x --;
        }
        while(!d.empty()){
            w.push_back(d.front());
            d.pop_front();
        }
        v.push_back(w);
    }

    for(int i = 0; i < v.size(); i ++){
        for(int j = 0; j < v[i].size(); j ++){
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }

}