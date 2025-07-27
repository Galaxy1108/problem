#include <bits/stdc++.h>
using namespace std;

long long r[6005];
vector<long long> a[6005];
long long is_nroot[6005];
long long dp[6005][2];

void dfs(long long this_node,long long father_node){
    dp[this_node][1] = r[this_node];
    for(long long its:a[this_node]){
        if(its==father_node){
            continue;
        }
        dfs(its,this_node);
        dp[this_node][0] += max(dp[its][1], dp[its][0]);
        dp[this_node][1] += dp[its][0];
    }
}

long long main(){
    long long n;
    cin >> n;
    for (long long i = 1; i <= n;i++){
        cin >> r[i];
    }
    for (long long i = 1; i < n;i++){
        long long u, v;
        cin >> u >> v;
        a[v].push_back(u);
        is_nroot[u] = true;
    }
    long long root;
    for (long long i = 1; i <= n;i++){
        if(!is_nroot[i]){
            root = i;
        }
    }
    dfs(root, -1);
    cout << max(dp[root][0], dp[root][1]);
}