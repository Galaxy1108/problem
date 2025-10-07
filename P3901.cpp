/**
 * @name 数列找不同
 * @link https://www.luogu.com.cn/problem/P3901
 * @par tags
 * #【模板】 #莫队
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

void add(int pos) {
    if (!cnt[a[pos]]) {
        anss++;
    }
    cnt[a[pos]]++;
}

void del(int pos) {
    cnt[a[pos]]--;
    if (!cnt[a[pos]]) {
        anss--;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
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
            del(L++);
        }
        while (L > l) {
            add(--L);
        }
        while (R < r) {
            add(++R);
        }
        while (R > r) {
            del(R--);
        }
        ans[que[i].id] = (anss == (r - l + 1));
    }
    for (int i = 1;i <= q;i++) {
        cout << (ans[i] ? "Yes\n" : "No\n");
    }
}