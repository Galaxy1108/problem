#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int its = 0;

    int T, n;
    cin >> T;
    while (T--) {
        string opt;
        cin >> opt;
        switch (opt[0]) {
        case 'M': {
            cin >> its;
            break;
        }
        case 'I': {
            cin >> n;
            string _str;
            _str.resize(n);
            getchar();
            for (int i = 0;i < n;i++) {
                _str[i] = getchar();
            }
            str.insert(its, _str);
            break;
        }
        case 'D': {
            cin >> n;
            str.erase(its, n);
            break;
        }
        case 'R': {
            cin >> n;
            reverse(str.begin() + its, str.begin() + its + n);
            break;
        }
        case 'G': {
            cout << str[its];
            if (str[its] != '\n') {
                cout << '\n';
            }
        }
        case 'P': {
            its--;
        }
        case 'N': {
            its++;
        }
        }
    }
}
