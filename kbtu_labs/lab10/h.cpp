#include <bits/stdc++.h>

using namespace std;

struct vertex{
    int r;
    int c;
    vertex(int r, int c){
        this -> r = r;
        this -> c = c;
    }
};

string s[101];
queue<vertex> q;

void step(int r, int c, int n, int m, int t){
    if(r < n && c < m && r >= 0 && c >= 0 && s[r][c] == '1'){
        s[r][c] = char(t);
        q.push(vertex(r, c));
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i ++){
        cin >> s[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(s[i][j] == '1'){
                cnt ++;
                s[i][j] = 'i';
                q.push(vertex(i, j));
                while(!q.empty()){
                    vertex cur = q.front();
                    q.pop();
                    int t = s[cur.r][cur.c];
                    step(cur.r + 1, cur.c, n, m, t + 1);
                    step(cur.r - 1, cur.c, n, m, t + 1);
                    step(cur.r, cur.c + 1, n, m, t + 1);
                    step(cur.r, cur.c - 1, n, m, t + 1);
                }
            }
        }
    }
    cout << cnt;
}