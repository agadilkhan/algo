#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n;
    cin >> n;

    while(n --) {
        long long a, b, q;
        cin >> a >> b >> q;

        while(q --) {
            long long l, r;
            cin >> l >> r;

            long long cnt = 0;
            if(r >= min(a, b) && l <= min(a, b)) {
                long long m_min = min(a, b);
                long long m_max = max(a, b);
                for(long long i = m_min; i <= r; i ++) {
                    if(((i % a) % b) != ((i % b) % a)) {
                        cnt ++;
                    }else {
                        cout << i << ' ';
                    }
                }
            }
            else if(l > max(a, b)) {
                long long max_num = max(a ,b)
                while (1) {  
                // if statement checks max_num is completely divisible by a and b.  
                    if(max_num % a == 0 && max_num % b == 0)  
                    {   
                            break;  
                    }  
                    max_num ++; // increment by 1 on each iteration  
                  }  
                cnt = (r / max_num - l / max_num) + l - max_num;
                
            }
            cout << cnt << endl;
        }
    }

}