#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int s[100005], f[100005];
char ans[100005];
int s_idx[100005];
int n, m, top;

bool tags[100005];

bool check(ll k){
    int this_s = 1;
    top = 0;
    for (int i = 1; i <= n;i++){
        tags[i] = false;
    }
    for (int i = 1; i <= n;i++){
        if(this_s>m){
            ans[++top] = 'R';
            continue;
        }
        if(f[this_s]<s[i]){
            if(f[this_s]<s[i]-k){
                return false;
            }
            s_idx[i] = f[this_s];
            while(this_s<=m && f[this_s]<=s[i]){
                this_s++;
            }
            if(top && ans[top]=='L' && s_idx[i-1]>=s[i]-k){
                tags[i] = true;
                while(this_s<=m && f[this_s]<=s[i-1]+k){
                    this_s++;
                }
            }
            ans[++top] = 'L';
            continue;
        }
        while(this_s<=m && f[this_s]<=s[i]+k){
            this_s++;
        }
        ans[++top] = 'R';
    }
    return (this_s > m);
}

int main(){
    // freopen("P10806_26.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> s[i];
    }
    for (int i = 1; i <= m;i++){
        cin >> f[i];
    }
    ll l = 0, r = INT_MAX;
    while(l<r){
        ll mid = (l + r) / 2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
        // cout << l << ' ' << r << endl;
    }
    if(!check(l)){
        cout << -1;
        return 0;
    }
    cout << l << '\n';
    for (int i = 1; i <= n;i++){
        tags[i] = false;
    }
    int this_s = 1;
    top = 0;
    for (int i = 1; i <= n;i++){
        tags[i] = false;
        if(this_s>m){
            ans[++top] = 'R';
            continue;
        }
        if(f[this_s]<s[i]){
            s_idx[i] = f[this_s];
            while(this_s<=m && f[this_s]<=s[i]){
                this_s++;
            }
            // cout << s[i]-l << ' ' << s_idx[i-1] << endl;
            if(top && ans[top]=='L' && s_idx[i-1]>=s[i]-l){
                tags[i] = true;
                while(this_s<=m && f[this_s]<=s[i-1]+l){
                    this_s++;
                }
            }
            ans[++top] = 'L';
            continue;
        }
        while(this_s<=m && f[this_s]<=s[i]+l){
            this_s++;
        }
        ans[++top] = 'R';
    }
    // for (int i = 1; i <= n;i++){
    //     cout << ans[i];
    // }
    // cout << endl;
    // for (int i = 1; i <= n;i++){
    //     cout << tags[i];
    // }
    // cout << endl;
    for (int i = n; i >= 1;i--){
        if (!tags[i]){
            continue;
        }
        tags[i - 1] = false;
        ans[i - 1] = 'R';
    }
    for (int i = 1; i <= n;i++){
        cout << ans[i];
    }
    return 0;
}