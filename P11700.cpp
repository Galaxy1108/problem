#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mod 1000000007

ll f[205][10][10][10][10][10][10];
ll a[205];

int main(){
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    ll anss = 0;
    f[0][0][0][0][0][0][0] = 1;
    for (int i = 1; i <= n;i++)
    for (int num_1 = 0; num_1 <= min(6ll, a[i]                                        ) * (k >= 7); num_1++)
    for (int num_2 = 0; num_2 <= min(5ll, a[i] - num_1                                ) * (k >= 6); num_2++)
    for (int num_3 = 0; num_3 <= min(4ll, a[i] - num_1 - num_2                        ) * (k >= 5); num_3++)
    for (int num_4 = 0; num_4 <= min(3ll, a[i] - num_1 - num_2 - num_3                ) * (k >= 4); num_4++)
    for (int num_5 = 0; num_5 <= min(2ll, a[i] - num_1 - num_2 - num_3 - num_4        ) * (k >= 3); num_5++)
    for (int num_6 = 0; num_6 <= min(1ll, a[i] - num_1 - num_2 - num_3 - num_4 - num_5) * (k >= 2); num_6++)
    for (int num_s = 0; num_s < (1 << k);num_s++)
    if (num_1 + num_2 + num_3 + num_4 + num_5 + num_6 + __builtin_popcount(num_s) == a[i]){
        int new_1 = (num_2 + (!!(num_s & (1 << 5)))) * (k >= 7);
        int new_2 = (num_3 + (!!(num_s & (1 << 4)))) * (k >= 6);
        int new_3 = (num_4 + (!!(num_s & (1 << 3)))) * (k >= 5);
        int new_4 = (num_5 + (!!(num_s & (1 << 2)))) * (k >= 4);
        int new_5 = (num_6 + (!!(num_s & (1 << 1)))) * (k >= 3);
        int new_6 = (         !!(num_s & (1 << 0)) ) * (k >= 2);
        f[i][new_1][new_2][new_3][new_4][new_5][new_6] = (f[i    ][new_1][new_2][new_3][new_4][new_5][new_6] +
                                                          f[i - 1][num_1][num_2][num_3][num_4][num_5][num_6]) % mod;
        if(i==n){
            anss = (anss + f[i - 1][num_1][num_2][num_3][num_4][num_5][num_6]) % mod;
        }
    }
    cout << anss;
}
        