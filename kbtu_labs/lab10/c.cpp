#include <bits/stdc++.h>

using namespace std;

vector <int> g[100001]; 
vector<bool> used(100001);
vector<int> p(100001);

int main(){
    int a, b;
    cin >> a >> b;

    if(a > b){
        cout << a - b << endl;
        for(int i = a - 1; i >= b; i--){
            cout << i << " ";
        }
        return 0;
    }

    int c = -1, s = 0, t = 2 , d = 2;

    g[a].push_back(a*2);
    g[a].push_back(a-1);
    queue<int> q;
    q.push(a);

    used[a] = true;
    p[a] = -1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        c++;
        if(c > t){
            t = d + d * 2;
            d *= 2;
            s ++;
        } 
        if(v == b){
            break;
        }
        for (int i=0; i < g[v].size(); i ++) {
            int to = g[v][i];
            if(to * 2 - b < a){
                g[to].push_back(to * 2);
            }
            g[to].push_back(to - 1);
            if (!used[to]) {
                used[to] = true;
                q.push(to);
                p[to] = v;  
            }
        }
    }

   
    if (!used[b]) cout << -1;
    else{
        vector<int> path;
        for (int v = b; v != -1; v = p[v])
            path.push_back(v);
        reverse (path.begin(), path.end());
        cout << path.size() - 1 << endl;
        for (size_t i=1; i<path.size(); ++i)
            cout << path[i] << " ";
    }

    return 0;
}