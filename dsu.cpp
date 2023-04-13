#include <iostream>

using namespace std;

int p[100000];
int r[100000];

void init_dsu(){
    for(int i = 1; i < 100000; i ++){
        p[i] = i;
    }
}

int find(int v){
    if(p[v] == v) return v;
    else{
        return p[v] = find(p[v]);
    }
}

bool merge(int a, int b){
    int root_a = find(a);
    int root_b = find(b);
    if(root_a == root_b) return true;
    else{
        if(r[root_a] > r[root_b]){
            p[root_b] = root_a;
        }else if(r[root_a] < r[root_b]){
            p[root_a] = root_b;
        }else{
            p[root_a] = root_b;
            r[root_b] ++;
        }
        return false;
    }
}

int main(){

    init_dsu();
    merge(1, 2);
    merge(3, 6);
    merge(1, 6);
    merge(4, 5);
    merge(4, 1);

    for(int i = 1; i <= 6; i ++){
        cout << p[i] << ' ';
    }
}