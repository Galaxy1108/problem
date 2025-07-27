#include <bits/stdc++.h>
using namespace std;

vector<long long> flors[16005];
long long ver[16005];
long long dp[16005];
long long anss;

void dfs(long long this_node,long long father_node){
    dp[this_node] = ver[this_node];
    for(long long its:flors[this_node]){
        if(its==father_node){
            continue;
        }
        dfs(its, this_node);
        if(dp[its]>0){
            dp[this_node] += dp[its];
        }
    }
    anss = max(anss, dp[this_node]);
}


long long main(){
    anss = LLONG_MIN;
    long long n;
    cin >> n;
    for (long long i = 1; i <= n;i++){
        cin >> ver[i];
    }
    for (long long i = 0; i < n - 1;i++){
        long long u, v;
        cin >> u >> v;
        flors[u].push_back(v);
        flors[v].push_back(u);
    }
    dfs(1, -1);
    cout << anss;
    return 0;
}