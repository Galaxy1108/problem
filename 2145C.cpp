/**
 * problem: Monocarp's String
 * link: https://codeforces.com/problemset/problem/2145/C 
 * difficult: *1300 (yellow)
 * date: 2025/10/22 周三 15:26
 * tags: #二分 #哈希
 */

#include <bits/stdc++.h>
using namespace std;

string str;
int n;

unordered_map<int, int> idxs;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> str;
        str = " " + str;
        idxs.clear();
        int num = 0;
        for (int i = 1;i <= n;i++) {
            num += (str[i] == 'a' ? 1 : -1);
        }
        int num2 = 0;
        int anss = INT_MAX;
        idxs[0] = 1;
        for (int i = 1;i <= n;i++) {
            num2 += (str[i] == 'a' ? 1 : -1);
            idxs[num2] = i + 1;
            int need_n = num2 - num;
            if (idxs[need_n]) {
                anss = min(anss, i - idxs[need_n] + 1);
            }
        }
        cout << (anss == n ? -1 : anss) << '\n';
    }
}
