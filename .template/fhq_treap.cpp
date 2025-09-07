#include <bits/stdc++.h>
#include "all.h"
using namespace std;

data_struct::fhq_treap<int, 100005> trr;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int opt, x;
        cin >> opt >> x;
        switch (opt) {
        case 1:
            trr.insert(x);
            break;
        case 2:
            trr.erase(x);
            break;
        case 3:
            cout << trr.order_of_key(x) << '\n';
            break;
        case 4:
            cout << *trr.find_by_order(x) << '\n';
            break;
        case 5:
            cout << *trr.prev(x) << '\n';
            break;
        case 6:
            cout << *trr.next(x) << '\n';
            break;
        }
    }
    return 0;
}