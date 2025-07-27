#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> a[200005];
ll sums[200005];
ll n, k;

void dfs(ll this_node,ll father_node){
    ll ere_l = 1;
    if(father_node==-1){
        ere_l = 0;
    }
    for(auto its:a[this_node]){
        if(its==father_node){
            continue;
        }
        dfs(its, this_node);
        if(sums[its]==0){
            ere_l++;
        }
        sums[this_node] += sums[its];
    }
    sums[this_node]++;
    if(sums[this_node]<k){
        if(a[this_node].size()-ere_l>=2){
            cout << "No";
            exit(0);
        }
    }else if(sums[this_node]>k){
        cout << "No";
        exit(0);
    }else{
        if(a[this_node].size()-ere_l>=3){
            cout << "No";
            exit(0);
        }
        sums[this_node] = 0;
    }
}

long long main(){
    cin >> n >> k;
    for (ll i = 0; i < n * k - 1;i++){
        ll v1, v2;
        cin >> v1 >> v2;
        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }
    dfs(1, - 1);
    cout << "Yes";
}