#include <bits/stdc++.h>

using namespace std;

vector<int> g[100001];
bool used[100001];
int d[100001];

int main(){

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i ++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int s, f;
    cin >> s >> f;

    queue<int> q;
    q.push(s);
    used[s] = true;
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i ++){
            int to = g[v][i];
            if(!used[to]){
                used[to] = true;
                q.push(to);
            }
        }
    }
    if(used[f]){
        cout << "YES";
        return 0;
    }
    cout << "NO";
}