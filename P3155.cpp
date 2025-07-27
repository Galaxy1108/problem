#include <bits/stdc++.h>
using namespace std;

long long dp[10005][2];
vector<long long> maps[10005];

void dfs(long long this_node,long long father_node){
    for(long long its:maps[this_node]){
        if(its==father_node){
            continue;
        }
        dfs(its, this_node);
        dp[this_node][0] += min(dp[its][0] - 1, dp[its][1]);
        dp[this_node][1] += min(dp[its][1] - 1, dp[its][0]);
    }
}

long long main(){
    long long m, n;
    cin >> m >> n;
    for (long long i = 1; i <= n;i++){
        long long c;
        cin >> c;
        dp[i][c] = 1, dp[i][!c] = long long_MAX;
    }
    for (long long i = 0; i < m - 1;i++){
        long long u, v;
        cin >> u >> v;
        maps[u].push_back(v);
        maps[v].push_back(u);
    }
    for (long long i = n + 1; i <= m;i++){
        dp[i][0] = dp[i][1] = 1;
    }
    dfs(m, -1);
    cout << min(dp[m][0], dp[m][1]);
    return 0;
}