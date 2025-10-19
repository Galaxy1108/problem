#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> history;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Q;
    cin >> Q;
    int cnt = 0, min_cnt = 0;
    history.push({ 0, 0 });
    while (Q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            char c;
            cin >> c;
            history.push({ cnt, min_cnt });
            if (c == '(') {
                cnt++;
            } else {
                cnt--;
            }
            min_cnt = min(min_cnt, cnt);
        } else {
            pair<int,int> h = history.top();
            history.pop();
            cnt = h.first;
            min_cnt = h.second;
        }
        if (cnt == 0 && min_cnt >= 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
