#include <iostream>
#include <iomanip>

using namespace std;

struct Student
{
    string lname, fname;
    double gpa = 0;
};

int partition(Student s[], int l, int h){
    Student pivot = s[h];
    int i = l - 1;
    for(int j = l; j < h; j ++){
        if(s[j].gpa < pivot.gpa){
            i ++;
            swap(s[j], s[i]);
        }
        else if(s[j].gpa == pivot.gpa){
            if(s[j].lname < pivot.lname){
                i ++;
                swap(s[j], s[i]);
            }else if(s[j].lname == pivot.lname){
                if(s[j].fname < pivot.fname){
                    i ++;
                    swap(s[j], s[i]);
                }
            }
        }
    }
    swap(s[i + 1], s[h]);
    return i + 1;
}

void qsort(Student s[], int l, int h){
    if(l < h){
        int p = partition(s, l, h);
        qsort(s, l, p - 1);
        qsort(s, p + 1, h);
    }
}

int main(){

    int n;
    cin >> n;
    Student s[n];

    for(int i = 0; i < n; i ++){
        string lname, fname;
        int x;
        cin >> lname >> fname >> x;
        s[i].lname = lname, s[i].fname = fname;
        int sumOfCredits = 0;
        while(x --){
            string grade;
            int credit;
            cin >> grade >> credit;
            double gpa = 0;
            if(grade == "A+") gpa = 4;
            else if(grade == "A") gpa = 3.75;
            else if(grade == "B+") gpa = 3.5;
            else if(grade == "B") gpa = 3;
            else if(grade == "C+") gpa = 2.5;
            else if(grade == "C")  gpa = 2;
            else if(grade == "D+") gpa = 1.5;
            else if(grade == "D") gpa = 1;
            s[i].gpa += gpa * credit;
            sumOfCredits += credit;
        }
        s[i].gpa /= sumOfCredits;
    }

    qsort(s, 0, n - 1);

    for(auto i : s){
        cout << i.lname << " " << i.fname << " " << fixed << setprecision(3) << i.gpa << endl; 
    }
}