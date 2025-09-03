#include <bits/stdc++.h>
using namespace std;

string strs[105];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> strs[i];
    }
    int num;
    string s;
    cin >> num >> s;
    cout << (strs[num] == s ? "Yes" : "No");
}