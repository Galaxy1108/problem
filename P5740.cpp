#include <bits/stdc++.h>
using namespace std;

struct student{
    string name;
    int Chinese=0,Math=0,English=0;
    int pm=0;
};

bool student_cmp(student a,student b){
    return (((a.Chinese+a.English+a.Math)>(b.Chinese+b.English+b.Math)) || ((a.Chinese+a.English+a.Math)==(b.Chinese+b.English+b.Math) && (a.pm<b.pm)));
}

int main(){
    int n;
    cin>>n;
    student students[n];
    for(int i=0;i<n;i++){
        //cout<<i<<endl;
        cin>>students[i].name>>students[i].Chinese>>students[i].Math>>students[i].English;
        students[i].pm=i;
    }
    sort(students,students+n,student_cmp);
    cout<<students[0].name<<" "<<students[0].Chinese<<" "<<students[0].Math<<" "<<students[0].English;
    return 0;
}
