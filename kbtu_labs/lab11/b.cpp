#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > g[100001];
bool used[100001];

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    
    for(int i = 1; i <= n; i ++){
        for(int j = i + 1; j <= n; j ++){
            g[i].push_back({j, a[i] + a[j]});
            g[j].push_back({i, a[i] + a[j]});
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