#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<pair<int, int> > g[100001];
bool used[100001];

int main(){

    int n, m;
    cin >> n >> m;

    int x, y;
    cin >> x >> y;
    int m_min = min(x, y);

    for(int i = 0; i < m; i ++){
        string s;
        cin >> s;
        int a, b, c;
        cin >> a >> b >> c;
        if(s == "both"){
            g[a].push_back({b, c * m_min});
            g[b].push_back({a, c * m_min});
        }
        else if(s == "big"){
            g[a].push_back({b, c * x});
            g[b].push_back({a, c * x});
        }
        else if(s == "small"){
            g[a].push_back({b, c * y});
            g[b].push_back({a, c * y});
        }
    }


    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push({0, 1});
    int cost = 0;
    while(!q.empty()){
        pair<int, int> p = q.top();
        q.pop();
        int mst = p.first, v = p.second;
        if(used[v]) continue;
        used[v] = true;
        cost += mst;
        for(pair<int, int> e : g[v]){
            int u = e.first, weight = e.second;
            if(!used[u]){
                q.push({weight, u});
            }
        }
    }
    cout << cost;
}