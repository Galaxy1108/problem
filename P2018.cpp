#include <bits/stdc++.h>
using namespace std;

vector<long long> a[1005];
long long dp[1005];
long long sons[1005];

bool cmp(long long a, long long b) {
    return a > b;
}

void dfs(long long this_node, long long father_node) {
    long long tops = 0;
    for (long long its : a[this_node]) {
        if (its == father_node) {
            continue;
        }
        dfs(its, this_node);
    }
    for (long long its : a[this_node]) {
        if (its == father_node) {
            continue;
        }
        sons[++tops] = dp[its];
    }
    sort(sons + 1, sons + tops + 1, cmp);
    for (long long i = 1; i <= tops;i++) {
        dp[this_node] = max(dp[this_node], sons[i] + i);
    }
}

long long anss[1005];

int main() {
    long long n;
    cin >> n;
    for (long long i = 2; i <= n;i++) {
        long long fat;
        cin >> fat;
        a[fat].push_back(i);
        a[i].push_back(fat);
    }
    long long ansst = LLONG_MAX;
    for (long long i = 1; i <= n;i++) {
        memset(dp, 0, sizeof(dp));
        dfs(i, -1);
        anss[i] = dp[i] + 1;
        ansst = min(ansst, anss[i]);
    }
    cout << ansst << '\n';
    for (long long i = 1; i <= n;i++) {
        if (anss[i] == ansst) {
            cout << i << ' ';
        }
    }
    return 0;
}