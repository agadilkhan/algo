#include <iostream>
#include <iomanip>

using namespace std;

struct Student
{
    string lname, fname;
    double gpa = 0;
};

void merge(Student s[], int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    Student L[n1];
    for(int i = 0; i < n1; i ++){
        L[i] = s[i + l1];
    }

    int n2 = r2 - l2 + 1;
    Student R[n2];
    for(int i = 0; i < n2; i ++){
        R[i] = s[i + l2];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;
    while(i1 < n1 and i2 < n2){
        if(L[i1].gpa == R[i2].gpa){
            if(L[i1].lname == R[i2].lname){
                if(L[i1].fname < R[i2].fname){
                    s[i] = L[i1];
                    i1 ++;
                }else{
                    s[i] = R[i2];
                    i2 ++;
                }
            }else{
                if(L[i1].lname < R[i2].lname){
                    s[i] = L[i1];
                    i1 ++;
                }else{
                    s[i] = R[i2];
                    i2 ++;
                }
            }
        }else{
            if(L[i1].gpa < R[i2].gpa){
                s[i] = L[i1];
                i1 ++;
            }else{
                s[i] = R[i2];
                i2 ++;
            }
        }
        i ++;
    }

    for( ; i1 < n1; i1 ++){
        s[i] = L[i1];
        i ++;
    }
    for( ; i2 < n2; i2 ++){
        s[i] = R[i2];
        i ++;
    }
}

void msort(Student s[], int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        msort(s, l, mid);
        msort(s, mid + 1, r);
        merge(s, l, mid, mid + 1, r);
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

    msort(s, 0, n - 1);

    for(auto i : s){
        cout << i.lname << ' ' << i.fname << ' ' << fixed << setprecision(3) << i.gpa << endl;
    }

}