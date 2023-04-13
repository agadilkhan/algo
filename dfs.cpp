#include <iostream>
#include <vector>

using namespace std;

vector<int> g[10001];
bool used[10001];

void dfs(int v){
    if(used[v]) return;
    cout << v << endl;
    used[v] = true;
    for(int i = 0; i < g[v].size(); i ++){
        int to = g[v][i];
        if(!used[to]){
            dfs(to);
        }
    }

}

int main(){

    int n, m;
    cin >> n >> m;

    while(m --){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(2);
}   