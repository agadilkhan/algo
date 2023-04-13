#include <iostream>

using namespace std;

int partition(string &s, int l, int h){
    int pivot = s[h];
    int i = l - 1;
    for(int j = l; j < h; j ++){
        if(s[j] < pivot){
            i ++;
            swap(s[i], s[j]);
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

    int n;
    cin >> n;

    string s;
    cin >> s;

    int i = -1;
    for(int j = 0; j < s.size(); j ++){
        if(s[j] == 'a' or s[j] == 'e' or s[j] == 'o' or s[j] == 'i' or s[j] == 'u'){
            i ++;
            swap(s[i], s[j]);
        }
    }
    qsort(s, 0, i);
    qsort(s, i + 1, n - 1);

    cout << s;

}