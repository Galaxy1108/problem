#include <bits/stdc++.h>
using namespace std;

long double sn[10];

int main() {
    long double sums = 0, anss = 1;
    for (int i = 1;i <= 7;i++) {
        cin >> sn[i];
        sums += sn[i];
    }
    long double anss = 0;
    for (int i = 1;i <= 6;i++) {
        anss = anss * sn[i] / (sums + 1 - i) * i;
    }
    anss = anss * sn[7] * 7;
    printf("%.3f",)
}