#include <bits/stdc++.h>
using namespace std;

long long idxs[500005];

int main(){
    long long T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        string str;
        cin >> str;
        long long len_0 = 0, len_1 = 0;
        long long max_0 = 0, max_1 = 0;
        long long idx_0 = 0, idx_1 = 0;
        long long idxt = 0; //连续段个数
        for (long long i = 0;i < n;i++) {
            if (i == 0 || str[i] != str[i - 1]) {
                idxt++;
            }
            idxs[i] = idxt;
            if (str[i] == '0') {
                len_0++;
                if (len_0 > max_0) {
                    max_0 = len_0;
                    idx_0 = idxt;
                }
                len_1 = 0;
            } else {
                len_1++;
                if (len_1 > max_1) {
                    max_1 = len_1;
                    idx_1 = idxt;
                }
                len_0 = 0;
            }
        }
        // cout << idx_0 << '\n';
        long long anss1 = 0;
        for (long long i = 0;i < n;i++) {
            if (idxs[i] == idx_0) {
                continue;
            }
            if (str[i] == '0') {
                anss1 += 2;
            } else {
                anss1 ++;
            }
        }
        //calc all 1
        long long anss2 = 0;
        for (long long i = 0;i < n;i++) {
            if (idxs[i] == idx_1) {
                continue;
            }
            if (str[i] == '1') {
                anss2 += 2;
            } else {
                anss2 ++;
            }
        }
        cout << min(anss1, anss2) << '\n';
    }
}