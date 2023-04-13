#include <iostream>
#include <deque>

using namespace std;

int main(){

    char c;
    int k;
    deque<int> d;

    while(cin >> c){
        if(c == '!') break;
        else{
            if(c == '*'){
                if(!d.empty()){
                    if(d.size() == 1){
                        cout << 2 * d.front() << endl;
                        d.pop_front();
                    }
                    else{
                        cout << d.front() + d.back() << endl;
                        d.pop_back();
                        d.pop_front();
                    }
                }
                else{
                    cout << "error" << endl;
                }
            }
            else{
                cin >> k;
                if(c == '+') d.push_front(k);
                else d.push_back(k);
            }
        }
    }

}