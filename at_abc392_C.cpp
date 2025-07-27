#include <bits/stdc++.h>
using namespace std;

long long idx_look[300005], idx_bib[300005], bib_idx[300005];

long long main(){
    long long n;
    cin >> n;
    for (long long i = 1; i <= n;i++){
        cin >> idx_look[i];
    }
    for (long long i = 1; i <= n;i++){
        cin >> idx_bib[i];
        bib_idx[idx_bib[i]] = i;
    }
    for (long long i = 1; i <= n;i++){
        cout << idx_bib[idx_look[bib_idx[i]]] << ' ';
    }
    return 0;
}

/*
小明有n个色子，每个色子有k_i个面，对于第 i 个色子的第 j 个面写着 A_{i,j}.
当你掷这个骰子时，每个面出现的概率为  1/k_i

小明现在想让你告诉他，如果从 N 个骰子中选择两个骰子并掷出。在最佳选择骰子的情况下，两颗骰子出现相同数字的最大概率。

数据范围
2<=n<=100
1<=k_i
k_1+k_2+..+k_n<=10^5
1<=A_{i,j}<=10^5

*/