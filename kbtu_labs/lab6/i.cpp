#include <iostream>

using namespace std;

int partition(string &s, int l, int h){
    char pivot = s[h];
    int i = l - 1;
    for(int j = l; j < h; j ++){
        if(s[j] < pivot){
            i ++;
            swap(s[j], s[i]);
        }
    }
    swap(s[i + 1], s[h]);
    return i + 1;
}

void qsort(string &s, int l, int h){
    if(l < h){
        int p = partition(s, l, h);
        qsort(s, l, p - 1);
        qsort(s, p + 1, h);
    }
}

int main(){

    string s;
    cin >> s;

    qsort(s, 0, s.size() - 1);

    cout << s;

}