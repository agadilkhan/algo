#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[10001];
bool used[10001];

int main(){

    int n, m;
    cin >> n >> m;

    while(m --){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    used[1] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i ++){
            int to = g[v][i];
            if(!used[to]){
                used[to] = true;
                q.push(to);
                cout << to << endl;
            }
        }
    }
}