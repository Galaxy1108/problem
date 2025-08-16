#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    if(str=="red"){
        cout << "SSS";
        return 0;
    }
    if (str == "blue") {
        cout << "FFF";
        return 0;
    }
    if (str == "green") {
        cout << "MMM";
        return 0;
    }
    cout << "Unknown";
}