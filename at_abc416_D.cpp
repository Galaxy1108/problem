#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[300005], b[300005];

int main(){
    ll T;
    cin >> T;
    while(T--){
        ll n, m;
        cin >> n >> m;
        ll sum_a = 0, sum_b = 0;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
            sum_a += a[i];
        }
        for (int i = 1; i <= n;i++){
            cin >> b[i];
            sum_b += b[i];
        }
        sort(a + 1, a + 1 + n, [](ll a, ll b)
             { return a > b; });
        sort(b + 1, b + 1 + n, [](ll a, ll b)
             { return a > b; });
        ll this_a = 1, this_b = n, cnts = 0;
        while(this_a<=n && this_b>=1){
            if(a[this_a]+b[this_b]<m){
                this_b--;
            }else{
                cnts++;
                this_b--;
                this_a++;
            }
        }
        cout << sum_a + sum_b - m * cnts << '\n';
    }
}