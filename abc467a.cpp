#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    double bmi = (double)w / (h * h) * 10000;
    if (bmi >= 25.0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
