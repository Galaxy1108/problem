#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005];
int pa[200005], anss[200005][2];
int n, m;

void work(int x, int y) {
	if (x == y) {
		return;
	}
    anss[++m][0] = x;
	anss[m][1] = y;
	swap(a[x], a[y]);
	swap(pa[a[x]], pa[a[y]]);
	swap(b[x], b[y]);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
	    for (int i = 1; i <= n; i++) {
	    	cin >> a[i];
	    	pa[a[i]] = i;
	    }
	    for (int i = 1; i <= n; i++) {
	    	cin >> b[i];
	    }
	    m = 0;
        int num = 0;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
	    	if (a[i] == b[i]) {
	    		if (n % 2 == 0 || num) {
                    flag = false;
                    break;
                }
	    		num = i;
	    	} else if (b[pa[b[i]]] != a[i]) {
	    		flag = false;
                break;
	    	}
	    }
        if (!flag) {
            cout << -1 << '\n';
            continue;
        }
	    if (n % 2) {
	    	work(num, (n + 1) / 2);
	    }
	    for (int i = 1; i <= n / 2; ++i) {
	    	work(pa[b[i]], n - i + 1);
	    }
	    cout << m << '\n';
	    for (int i = 1; i <= m; ++i) {
	    	cout << anss[i][0] << ' ' << anss[i][1] << '\n';
	    }
	}
	return 0;
}