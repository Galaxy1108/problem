#include <iostream>
using namespace std;

int r[5][5][2] = {
                 {{0,0},{0,1},{1,0},{1,0},{0,1}},
                 {{1,0},{0,0},{0,1},{1,0},{0,1}},
                 {{0,1},{1,0},{0,0},{0,1},{1,0}},
                 {{0,1},{0,1},{1,0},{0,0},{1,0}},
                 {{1,0},{1,0},{0,1},{0,1},{0,0}},
};

int main() {
    int n;
    int an;
    int bn;
    cin >> n >> an >> bn;
    int a[an], b[bn];
    for (int i = 0; i < an;i++) {
        cin >> a[i];
    }
    for (int i = 0; i < bn;i++) {
        cin >> b[i];
    }
    int ann;
    int bnn;
    int nn;
    int aa;
    int bb;
    ann = bnn = nn = aa = bb = 0;
    for (;;) {
        if (nn == n) {
            break;
        }
        if (ann == an) {
            ann = 0;
        }
        if (bnn == bn) {
            bnn = 0;
        }
        aa += r[a[ann]][b[bnn]][0];
        bb += r[a[ann]][b[bnn]][1];
        ann++;
        bnn++;
        nn++;
    }
    cout << aa << ' ' << bb;
    return 0;
}