#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, f;
    cin >> d >> f;
    for(int i = f; ; i += 7) {
        if(i > d) {
            cout << i - d;
            break;
        }
    }
    return 0;
}
