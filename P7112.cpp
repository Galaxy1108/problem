#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define N 600
ll sn[N + 5][N + 5], n, p;

int main(){
    // freopen("P7112.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n >> p;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> sn[i][j];
            // sn[i][j] %= p;
        }
    }
    bool is_f = false;
    for (int a = 1; a <= n;a++){
        for (int solve_x = a + 1; solve_x <= n;solve_x++){
            while(sn[a][a]){
                ll k = sn[solve_x][a] / sn[a][a];
                for (int i = a; i <= n ;i++){
                    sn[solve_x][i] = (((sn[solve_x][i] - k * sn[a][i]) % p) + p) % p;
                }
                swap(sn[a], sn[solve_x]);
                is_f ^= 1;
            }
            swap(sn[a], sn[solve_x]);
            is_f ^= 1;
        }
    }
    long long anss = (is_f ? -1 : 1);
    for (int i = 1; i <= n;i++){
        anss = (anss * sn[i][i]) % p;
    }
    cout << (anss + p) % p;
}
