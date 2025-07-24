#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll idxton[20005], tops;
ll a_num[20], a_tops;
unordered_map<ll, ll> ntoidx;
ll dp[20][20005][2];
ll c[200005];

struct ks{
    ll first, second;
    friend bool operator<(ks a, ks b){
        return c[a.first] * c[a.second] < c[b.first] * c[b.second];
    }
};
priority_queue<ks> p;

#define mod 1000000007

int main(){
    ll n, k;
    cin >> n >> k;
    ll this_num = 1;
    for (ll num_2 = 1;;num_2 *= 2){
        if (num_2 > n){
            break;
        }
        for (ll num_3 = 1;;num_3 *= 3){
            this_num = num_2 * num_3;
            if (this_num > n){
                break;
            }
            for (ll num_5 = 1;;num_5 *= 5){
                this_num = num_2 * num_3 * num_5;
                if (this_num > n){
                    break;
                }
                for (ll num_7 = 1;;num_7 *= 7){
                    this_num = num_2 * num_3 * num_5 * num_7;
                    if (this_num > n){
                        break;
                    }
                    idxton[++tops] = this_num;
                    // ntoidx[idxton[tops]] = tops;
                }
            }
        }
    }
    sort(idxton + 1, idxton + 1 + tops);
    for (int i = 1;i <= tops;i++){
        ntoidx[idxton[i]] = i;
    }
    while (n){
        a_num[++a_tops] = n % 10;
        n /= 10;
        // cout << a_num[a_tops] << ' ';
    }
    // cout << '\n';
    for (int dig = 1;dig <= 9;dig++){
        dp[1][ntoidx[dig]][dig > a_num[1]] = 1;
    }
    for (int i = 2;i <= a_tops;i++){
        for (int j = 1;j <= tops;j++){
            for (int dig = 1;dig <= 9;dig++){
                if (idxton[j] % dig){
                    continue;
                }
                ll idx_j = ntoidx[idxton[j] / dig];
                // cout << idx_j << ' ' << i << ' ' << j << ' '<< dig << ' ' << idxton[j] << '\n';
                if (dig < a_num[i]){
                    dp[i][j][0] += dp[i - 1][idx_j][0] + dp[i - 1][idx_j][1];
                    continue;
                }
                if (dig > a_num[i]){
                    dp[i][j][1] += dp[i - 1][idx_j][0] + dp[i - 1][idx_j][1];
                    continue;
                }
                dp[i][j][0] += dp[i - 1][idx_j][0];
                dp[i][j][1] += dp[i - 1][idx_j][1];
                // cout << dp[i][j][0] << ' ' << dp[i][j][1]<<' '<<i<<' '<<j<<' '<<dig << ' '<<idx_j << '\n';
            }
        }
    }
    for (int i = 1;i <= a_tops;i++){
        for (int j = 1;j <= tops;j++){
            c[j] += dp[i][j][0] + (i != a_tops) * dp[i][j][1];
            // cout << dp[i][j][0] << ' ' << dp[i][j][1] << ' ' << (i == a_tops ? 0 : dp[i][j][1]) << '\n';
        }
        // cout << c[j] << ' ';
    }
    sort(c + 1, c + 1 + tops);
    for (int i = 1;i <= tops;i++){
        p.push({ i,tops });
    }
    k = min(k, tops * tops);
    ll anss = 0;
    for (int i = 1;i <= k;i++){
        auto u = p.top();
        // cout << u.first << ' ' << u.second << '\n';
        p.pop();
        anss = (anss + c[u.first] * c[u.second] % mod) % mod;
        if (u.second != 1){
            p.push({ u.first,u.second - 1 });
        }
    }
    cout << anss;
    return 0;
}