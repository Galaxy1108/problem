/**
 * @name 小B的询问
 * @par tags
 * #莫队
 */

#include <bits/stdc++.h>
using namespace std;

#define bl(n) n / qn

int anss = 0;
int a[100005];
int cnt[100005];
int ans[100005];
int qn;

struct question_t {
    int l, r;
    int id;
};

question_t que[100005];

int main() {
    int n, q, k;
    cin >> n >> q >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    qn = sqrt(n);
    for (int i = 1;i <= q;i++) {
        cin >> que[i].l >> que[i].r;
        que[i].id = i;
    }
    sort(que + 1, que + 1 + q, [](question_t a, question_t b) {
        return (bl(a.l) == bl(b.l) ? bl(a.r) < bl(b.r) : bl(a.l) < bl(b.l));
    });
    int L = 1, R = 0;
    for (int i = 1;i <= q;i++) {
        int l = que[i].l, r = que[i].r;
        while (L < l) {
            anss -= 2 * cnt[a[L++]]-- - 1;
        }
        while (L > l) {
            anss += 2 * cnt[a[--L]]++ + 1;
        }
        while (R < r) {
            anss += 2 * cnt[a[++R]]++ + 1;
        }
        while (R > r) {
            anss -= 2 * cnt[a[R--]]-- - 1;
        }
        ans[que[i].id] = anss;
    }
    for (int i = 1;i <= q;i++) {
        cout << ans[i] << '\n';
    }
}

/*

*/