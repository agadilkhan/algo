#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i ++)
        cin >> a[i];

    int c, d;
    cin >> c >> d;

    int b[c][d];
    for(int i = 0; i < c; i ++){
        for(int j = 0; j < d; j ++){
            cin >> b[i][j];
        }   
    }    


    for(int i = 0; i < n; i ++){
        int row = -1, col = -1;
        for(int j = 0; j < c; j ++){
            int l = 0, r = d - 1;
            bool check = false;
            if(j % 2 == 0){
                while(l <= r){
                    int m = (l + r) / 2;
                    if(b[j][m] == a[i]){
                        row = j;
                        col = m;
                        check = true;
                        break;
                    }
                    else if(b[j][m] > a[i]){
                        l = m + 1;
                    }
                    else if(b[j][m] < a[i]){
                        r = m - 1;
                    }
                }
            }else{
                while(l <= r){
                        int m = (l + r) / 2;
                        if(b[j][m] == a[i]){
                            row = j;
                            col = m;
                            check = true;
                            break;
                        }
                        else if(b[j][m] > a[i]){
                            r = m - 1;
                        }
                        else{
                            l = m + 1;
                        }
                    }
                }
            if(check) break;
        }
        if(col == -1 and row == -1) cout << -1 << endl;
        else cout << row << ' ' << col << endl;
    }
    
}