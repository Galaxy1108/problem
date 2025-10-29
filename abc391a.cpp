#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    cin >> a;
    if(a=="N"){
        cout << "S";
    }else if(a=="E"){
        cout << "W";
    }else if(a=="W"){
        cout << "E";
    }else if(a=="S"){
        cout << "N";
    }else if(a=="NE"){
        cout << "SW";
    }else if(a=="NW"){
        cout << "SE";
    }else if(a=="SE"){
        cout << "NW";
    }else if(a=="SW"){
        cout << "NE";
    }
}