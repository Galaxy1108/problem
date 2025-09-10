#include <bits/stdc++.h>
using namespace std;

int num[10] = { 6,2,5,5,4,5,6,3,7,6 };
int a[2005];

int main() {
    int n;
    cin >> n;
    a[0] = 6;
    for (int i = 1; i <= 2000; i++) {
        for (int j = i; j; j /= 10) {
            a[i] += num[j % 10];
        }
    }
    
    int anss = 0;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (a[i] + a[j] + a[i + j] + 4 == n) {
                anss++;
            }
        }
    }
    cout << anss;
}