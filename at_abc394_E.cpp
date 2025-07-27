#include <bits/stdc++.h>
using namespace std;

char c[105][105];
long long anss[105][105];
queue<pair<long long, long long>> que;

long long main(){
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++){
        for (long long j = 0; j < n; j++){
            cin >> c[i][j];
            anss[i][j] = LLONG_MAX;
        }
    }
    for (long long i = 0; i < n; i++){
        que.push({i, i});
        anss[i][i] = 0;
    }
    for (long long i = 0; i < n; i++){
        for (long long j = 0; j < n; j++){
            if (i == j || c[i][j] == '-'){
                continue;
            }
            que.push({i, j});
            anss[i][j] = 1;
        }
    }
    while (!que.empty()){
        auto q = que.front();
        que.pop();
        long long node1 = q.first, node2 = q.second;
        for (long long i = 0; i < n; i++){
            for (long long j = 0; j < n; j++){
                if (c[i][node1] != '-' && c[node2][j] != '-' && c[i][node1] == c[node2][j] && anss[i][j] == LLONG_MAX){
                    anss[i][j] = anss[node1][node2] + 2;
                    que.push({i, j});
                }
            }
        }
    }
    for (long long i = 0; i < n; i++){
        for (long long j = 0; j < n; j++){
            cout << (anss[i][j] == LLONG_MAX ? -1 : anss[i][j]) << " \n"[j == n - 1];
        }
    }
}