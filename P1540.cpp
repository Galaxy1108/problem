#include <bits/stdc++.h>
using namespace std;

deque<int> q;

int main() {
    int n, m;
    cin >> m >> n;
    int anss = 0;
    while (n--) {
        int num;
        cin >> num;
        if (find(q.begin(), q.end(), num) != q.end()) {
            continue;
        }
        anss++;
        if (q.size() == m) {
            q.pop_front();
        }
        q.push_back(num);
    }
    cout << anss;
}