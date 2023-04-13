#include <bits/stdc++.h>

using namespace std;

vector<int> g[1001];

int main(){

    int n, d;
    cin >> n >> d;

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            int x;
            cin >> x;
            if(x == 1){
                g[i].push_back(j);
            }
        }
    }

    while(d --){
        int x, y, z;
        cin >> x >> y >> z;
        int cnt = 0;
        for(int i = 0; i < g[x].size(); i ++){
            if(y == g[x][i]){
                cnt ++;
            }
            if(z == g[x][i]){
                cnt ++;
            }
        }
        for(int i = 0; i < g[y].size(); i ++){
            if(x == g[y][i]){
                cnt ++;
            }
            if(z == g[y][i]){
                cnt ++;
            }
        }
        for(int i = 0; i < g[z].size(); i ++){
            if(x == g[z][i]){
                cnt ++;
            
            }
            if(y == g[z][i]){
                cnt ++;
            }
        }
        if(cnt == 6){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

}