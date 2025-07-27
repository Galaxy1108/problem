#include <bits/stdc++.h>
using namespace std;

long long bs[200005], wss[200005];

bool cmp(long long a,long long b){
    return a > b;
}

long long main(){
    long long n,m;
    cin >> n >> m;
    for (long long i = 0; i < n;i++){
        cin >> bs[i];
    }
    for (long long i = 0; i < m;i++){
        cin >> wss[i];
    }
    sort(bs, bs + n, cmp);
    sort(wss, wss + m, cmp);
    long long ms = min(n, m);
    long long anss = 0;
    for (long long i = 0;i< ms;i++){
        if((bs[i]>=0 && wss[i]>=0) || ((bs[i]<=0 && wss[i]>=0) && (bs[i]+wss[i]>=0))){
            anss += bs[i];
            anss += wss[i];
        }
        if(bs[i]>=0 && wss[i]<=0){
            anss += bs[i];
        }
    }
    for (long long i = ms; i < n;i++){
        if(bs[i]>=0){
            anss += bs[i];
        }
    }
        cout << anss;
}
/*
集合A有n个元素，集合B有m个元素
选择 0 个或更多的元素，使得所选集合A中的元素的数量至少等于所选集合B中的元素的数量。在所有这样的选择中，求所选球的数值之和的最大值。
*/