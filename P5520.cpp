#include <bits/stdc++.h>
using namespace std;

int main(){
    int type, n, m, p;
    cin >> type >> n >> m >> p;
    long long anss = 1;
    for (int i = n - m + 1; i >= n - 2 * m + 2;i--){
        anss = (anss * i) % p;
    }
    cout << anss;
}