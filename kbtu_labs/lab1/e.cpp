#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int main(){

    deque<int> d1, d2;
    
    int a[5], b[5];
    for(int i = 0; i < 5; i ++){
        cin >> a[i];
    }

    for(int i = 0; i < 5; i ++){
        cin >> b[i];
    }

    for(int i = 0; i < 5; i ++){
        if(a[i] > b[i]){
            if(a[i] == 9 and b[i] == 0){
                d2.push_back(a[i]);
                d2.push_back(b[i]);
            }
            else{
                d1.push_back(a[i]);
                d1.push_back(b[i]);
            }
        }
        else if(a[i] < b[i]){
            if(a[i] == 0 and b[i] == 9){
                d1.push_back(a[i]);
                d1.push_back(b[i]);
            }
            else{
                d2.push_back(a[i]);
                d2.push_back(b[i]);
            }
        }
    }   
    
    bool ok = true;
    int cnt = 5;

    while(!d1.empty() and !d2.empty()){
        if(d1.front() > d2.front()){
            if(d1.front() == 9 and d2.front() == 0){
                d2.push_back(d1.front());
                d2.push_back(d2.front());
                d1.pop_front();
                d2.pop_front();
            }
            else{
                d1.push_back(d1.front());
                d1.push_back(d2.front());
                d1.pop_front();
                d2.pop_front();
            }
        }
        else if(d2.front() > d1.front()){
            if(d1.front() == 0 and d2.front() == 9){
                d1.push_back(d1.front());
                d1.push_back(d2.front());
                d1.pop_front();
                d2.pop_front();
            }
            else{
                d2.push_back(d1.front());
                d2.push_back(d2.front());
                d1.pop_front();
                d2.pop_front();
            }
        }
        if(cnt > pow(10, 6)){
            ok = false;
            break;
        }
        cnt ++;
    }
    
    if(ok == true){
        if(d1.empty()) cout << "Nursik" << ' ' << cnt;
        else if(d2.empty()) cout << "Boris" << ' ' << cnt;
    }
    else{
        cout << "blin nichya";
    }

}