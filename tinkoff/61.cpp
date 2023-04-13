#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    int l, r;
};

bool cmp(Point p1, Point p2){
    return p1.r < p2.r;
}
int main(){

    int n, s;
    cin >> n >> s;

    Point p[n];
    for(int i = 0; i < n; i ++){
        cin >> p[i].l >> p[i].r;
    }
    sort(p, p+n, cmp);
    int sum = 0;
    for(int i = 0; i < n; i ++){
        sum += p[i].r;
    }

    if(sum <= s) {
        cout << p[n/2].r << endl;
    }else{
        for(int i = 0; i < n; i ++){
            while(p[i].r > p[i].l && sum != s && i != n/2){
                p[i].r --;
                sum --;

                // cout << p[i].l << ' ' << p[i].r  << ' ' << sum << endl;
            }
            if(sum == s) break;
        }
        cout << p[n/2].r << endl;
    }
}