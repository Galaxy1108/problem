#include <bits/stdc++.h>
using namespace std;

vector<long long> a;

int main() {
    long long n, m;
    cin >> m;
    for (long long i = 0; i < m; ++i) {
        char p;
        cin >> p;
        if (p == '1') {
            a.push_back(i);
        }
    }
    n = a.size();
    sort(a.begin(), a.end());
    vector<long long> b(n);
    for (long long i = 0; i < n; ++i) {
        b[i] = a[i] - i;
    }
    sort(b.begin(), b.end());

    long long k_min = 0;
    long long k_max = m - n + 1;

    long long mid = n / 2;
    long long k_candidate = b[mid];

    long long k_clamped = max(k_min, min(k_candidate, k_max));

    vector<long long> prefix(n + 1, 0);
    for (long long i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + b[i];
    }

    long long left_count = upper_bound(b.begin(), b.end(), k_clamped) - b.begin();
    long long sum_left = prefix[left_count];
    long long sum_right = prefix[n] - sum_left;

    long long total = (k_clamped * left_count - sum_left) + (sum_right - k_clamped * (n - left_count));
    cout << total << endl;
    return 0;
}