#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll fat[100005];

int main(){
    ll c, t;
    cin >> c >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        for (int i = 1; i <= n;i++){
            s[i] = 1;
        }
        for (int i = 1; i <= m;i++){
            char opt;
            cin >> opt;
            ll a, b;
            switch(opt){
                case 'T':
                    cin >> a;
                    s[a] = 3;
                    break;
                case 'F':
                    cin >> a;
                    s[a] = 3;
                    break;
                case 'U':
                    cin >> a;
                    s[a] = 4;
                    break;
                case '+':
                    cin >> a >> b;
                    s[a] = s[b];
                    break;
                case '-':
                    cin >> a >> b;
                    if(s[b]==1){

                    }
            }
        }
    }
}