#include <bits/stdc++.h>
using namespace std;

int s[200];

bool is_pri(int a) {
    if (a == 0 || a == 1) {
        return false;
    }
    for (int i = 2;i * i <= a;i++) {
        if (!(a % i)) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    cin >> str;
    size_t se = str.size();
    for (int i = 0;i < se;i++) {
        s[str[i]]++;
    }
    int maxs = numeric_limits<int>::min();
    int mins = numeric_limits<int>::max();
    for (int i = 'a';i <= 'z';i++) {
        if (!s[i]) {
            continue;
        }
        maxs = max(maxs, s[i]);
        mins = min(mins, s[i]);
	}
    is_pri(maxs - mins) ? cout << "Lucky Word\n" << maxs - mins : cout << "No Answer\n0";
} 