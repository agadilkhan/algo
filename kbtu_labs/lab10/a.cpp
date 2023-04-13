#include <iostream>
#include <queue>
#include <cmath>


using namespace std;

struct vertex{
    int r;
    int c;
    vertex(int r, int c){
        this->r = r;
        this->c = c;
    }
};

queue<vertex> q;
int a[1001][1001];

void step(int r, int c, int n, int m, int t){
    if(r <= n  && c <= m && r >= 1 && c >= 1 && a[r][c] == -1){
        a[r][c] = t;
        q.push(vertex(r, c));
    }   
}


int main(){

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
            if(a[i][j] == 2){
                a[i][j] = 0;
                q.push(vertex(i, j));
            }
            if(a[i][j] == 1){
                a[i][j] = -1;
            }
        }
    }

   
    while(q.size() > 0){
        vertex cur = q.front();
        q.pop();
        int t = a[cur.r][cur.c];
        step(cur.r + 1, cur.c, n, m, t + 1);
        step(cur.r - 1, cur.c, n, m, t + 1);
        step(cur.r, cur.c + 1, n, m, t + 1);
        step(cur.r, cur.c - 1, n, m, t + 1);
    }
    int mx = -1;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(a[i][j] == -1){
                cout << -1 << endl;
                return 0;
            }
            mx = max(a[i][j], mx);
        }
    }
    cout << mx;
}