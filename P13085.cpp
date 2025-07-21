#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[20][10];
ll dig_a[20], dig_b[20], a_cnt, b_cnt;

int main(){
    ll a, b;
    cin >> a >> b;
    for (ll i = 1; i <= 19;i++){
        for (ll num = 0; num <= 9;num++){
            if(i==1){
                dp[i][num] = 1;
                continue;
            }
            for (ll last_num = 0; last_num <= 9;last_num++){
                if(abs(num-last_num)<2){
                    continue;
                }
                dp[i][num] += dp[i - 1][last_num];
            }
        }
    }
    b++;
    while(a){
        dig_a[++a_cnt] = a % 10;
        a /= 10;
    }
    if(!a_cnt){
        dig_a[++a_cnt] = 0;
    }
    while(b){
        dig_b[++b_cnt] = b % 10;
        b /= 10;
    }
    if(!b_cnt){
        dig_b[++b_cnt] = 0;
    }
    ll anss1 = 0, f1 = true;
    for (ll i = a_cnt; i >= 1;i--){
        for (ll num = (i == a_cnt);f1 && num < dig_a[i];num++){
            if(i!=a_cnt && abs(num-dig_a[i+1])<2){
                continue;
            }
            anss1 += dp[i][num];
        }
        if(i==a_cnt){
            continue;
        }
        if(abs(dig_a[i]-dig_a[i+1])<2){
            f1 = false;
        }
        for (ll num = 1; num <= 9;num++){
            anss1 += dp[i][num];
        }
    }
    // anss1 += (f1 && !(1 != a_cnt && abs(dig_a[1] - dig_a[2]) < 2)) * dp[1][dig_a[1]];
    ll anss2 = 0, f2 = true;
    for (ll i = b_cnt; i >= 1;i--){
        for (ll num = (i == b_cnt); f2 && num < dig_b[i];num++){
            if(i!=b_cnt && abs(num-dig_b[i+1])<2){
                continue;
            }
            anss2 += dp[i][num];
        }
        if(i==b_cnt){
            continue;
        }
        if(abs(dig_b[i]-dig_b[i+1])<2){
            f2 = false;
        }
        for (ll num = 1; num <= 9;num++){
            anss2 += dp[i][num];
        }
    }
    // anss2 += (f2 && !(1 != a_cnt && abs(dig_b[1] - dig_b[2]) < 2)) * dp[1][dig_b[1]];
    // cout << anss2 << ' ' << anss1 << '\n';
    cout << anss2 - anss1;
    return 0;
}