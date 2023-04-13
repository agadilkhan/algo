#include <iostream>

using namespace std;

struct Date
{
    string year;
    string month;
    string day;
};

int partition(Date d[], int l, int h){
    Date pivot = d[h];
    int i = l - 1;
    for(int j = l; j < h; j ++){
        if(d[j].year < pivot.year){
            i ++;
            swap(d[j], d[i]);
        }else if(d[j].year == pivot.year){
            if(d[j].month < pivot.month){
                i ++;
                swap(d[j], d[i]);
            }else if(d[j].month == pivot.month){
                if(d[j].day < pivot.day){
                    i ++;
                    swap(d[j], d[i]);
                }
            }
        }
    }
    swap(d[i + 1], d[h]);
    return i + 1;
}

void qsort(Date d[], int l, int h){
    if(l < h){
        int p = partition(d, l, h);
        qsort(d, l, p - 1);
        qsort(d, p + 1, h);
    }
}


int main(){

    int n;
    cin >> n;

    Date d[n];

    for(int i = 0; i < n; i ++){
        string s;
        cin >> s;
        string day = "", year  = "", month = "";
        for(int i = 0; i < s.size(); i ++){
            if(i < 2){
                day += s[i];
            }else if(i > 2 and i < 5){
                month += s[i];
            }else if(i > 5){
                year += s[i];
            }
        }
        d[i].year = year;
        d[i].month = month;
        d[i].day = day;
    }

    qsort(d, 0, n - 1);
    
    for(int i = 0; i < n; i ++){
        cout << d[i].day << '-' << d[i].month << '-' << d[i].year << endl;
    }
}