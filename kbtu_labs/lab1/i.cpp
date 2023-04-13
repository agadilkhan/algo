#include <iostream>
#include <deque>

using namespace std;

int main(){

    int n;
    cin >> n;

    string s;
    cin >> s;

    deque<char> d;

    for(int i = 0; i < s.size(); i ++){
        d.push_back(s[i]);
    }

    int reqK = 0, reqS = 0;
    while(reqK <= d.size() and reqS <= d.size()){
        if(d.front() == 'K'){
            if(reqK == 0){
                reqS ++;
                d.push_back(d.front());
                d.pop_front();
            }else{
                d.pop_front();
                reqK --;
            }
        }else{
            if(reqS == 0){
                reqK ++;
                d.push_back(d.front());
                d.pop_front();
            }else{
                d.pop_front();
                reqS --;
            }
        }
    }
    if(d.front() == 'K') cout << "KATSURAGI";
    else cout << "SAKAYANAGI";
}