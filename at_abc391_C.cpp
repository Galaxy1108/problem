#include <bits/stdc++.h>
using namespace std;

long long gz[1000005];
long long n;
long long gc[1000005];
long long gc_p[1000005];

long long lowbit(long long a){
    return (a & (-a));
}

long long read(long long a){
    long long sums = 0;
    for (long long i = a; i > 0;i-=lowbit(i)){
        sums += gc[i];
    }
    return sums;
}

void add(long long a,long long k){
    for (long long i = a; i <= n;i+=lowbit(i)){
        gc[i] += k;
    }
}

long long main(){
    long long q;
    cin >> n >> q;
    for (long long i = 1; i <= n;i++){
        gz[i] = i;
        gc_p[i] = 1;
    }
    while(q--){
        long long opt;
        cin >> opt;
        if(opt==1){
            long long p, h;
            cin >> p >> h;
            gc_p[gz[p]]--;
            if(gc_p[gz[p]]==1){
                add(gz[p], -1);
            }
            gc_p[h]++;
            if(gc_p[h]==2){
                add(h,1);
            }
            gz[p] = h;
        }else{
            cout << read(n) << '\n';
        }
    }
}

/*
我在luogu上遇到了一道题，希望你能帮我给出解决方法：

时限：2s 
空限：1GB

小明的家中有一个网格，网格中有 10^9 行和 W 列。

有些网格中拥有图块，总共有 N 个图块。开始时，图块位于 (X_i,Y_i) 。

在每一时间刻（T=1,2,3...），根据以下规则移动这些图块：

 如果整个底行都布满了图块，那么底行的所有图块都会被移走。
 对于剩余的每个图块，按照从下到上的顺序，执行以下操作：
    1.如果该图块位于最下面一行，或者它下面的单元格中有一个图块，则不做任何操作。
    2.否则，将该图块向下移动一格。
 

给你 k 个查询。对第 k 个查询 (j,A_j)，小明希望你回答在 T_j+0.5 时刻是否存在图块 A_j 。

数据范围：
1<=N<=2*10^5
1<=W<=N
i<=X_i,Y_i<=W
1<=T_j<=10^9
不存在位置重复图块

样例：
in
5 3
1 1
1 2
2 2
3 2
2 3
6
1 1
1 2
2 3
2 5
3 4
3 5

out:
Yes
Yes
No
Yes
No
Yes
*/