#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    double anss = 0;
    for (int i = 0;i < str.size();i++) {
        for (int j = i + 2;j < str.size();j++) {
            string sub_str = str.substr(i, j - i + 1);
            // cout << sub_str << '\n';
            if (sub_str[0] != 't' || sub_str[sub_str.size() - 1] != 't') {
                continue;
            }
            int cnt = 0;
            for (int k = 1;k < sub_str.size() - 1;k++) {
                cnt += (sub_str[k] == 't');
            }
            anss = max(anss, (cnt * 1.0) / (sub_str.size() - 2));
        }
    }
    printf("%.12f", anss);
    return 0;
}