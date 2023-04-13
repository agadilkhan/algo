#include <iostream>
#include <vector>

using namespace std;

vector<int> p;
vector<vector<int>> g;  
int find_set(int v) {
    if (v == p[v]) {
        return v;
    }
    return p[v] = find_set(p[v]);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        p[a] = b;
        return true;
    }
    return false;
}

int main(){
    int n, m, x, y;
    cin >> n >> m;
    g.resize(n);
    p.resize(n);
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        x--; 
        y--;
        g[x].push_back(y);
        g[y].push_back(x); 
    }
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    vector<int> res;
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        res.push_back(cnt);
        cnt++;
        for(int j = 0; j < g[i].size(); j++){
            if(g[i][j] > i && union_sets(i, g[i][j])) cnt--;
        }
    }
    for(int i = res.size() - 1; i >= 0; i--){
        cout << res[i] << endl;
    }
}