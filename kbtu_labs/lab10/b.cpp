#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[101];
int d[101];
bool u[101];

int main(){

    int n;
    cin >> n;

    int a[n][n];
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            int x;
            cin >> x;
            if(x == 1){
                g[i].push_back(j);
            }
        }
    }

    int s, f;
    cin >> s >> f;

    queue<int> q;
    q.push(s);
    u[s] = true;
    d[s] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i ++){
            int t = g[v][i];
            if(!u[t]){
                u[t] = true;
                q.push(t);
                d[t] = d[v] + 1;
            }
        }
    }
    if(d[f] == 0){
        cout << -1;
    }else{
        cout << d[f];
    }
}