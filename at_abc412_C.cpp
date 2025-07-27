/*
#### 问题陈述

有 $N$ 张多米诺骨牌，编号从 $1$ 到 $N$ 。多米诺骨牌 $i$ 的大小是 $S_i$ 。  
考虑将一些骨牌从左到右排成一行，然后将它们推倒。当骨牌 $i$ 倒向右边时，如果紧靠骨牌 $i$ 右边的骨牌的大小最多为 $2 S_i$ ，那么该骨牌也会倒向右边。

您决定选择两张或更多骨牌，并将它们从左到右排成一行。骨牌的排列必须满足以下条件：

- 最左边的骨牌是骨牌 $1$ 。
- 最右边的骨牌是骨牌 $N$ 。
- 当只有骨牌 $1$ 向右倒下时，骨牌 $N$ 最终也会向右倒下。

是否存在满足条件的骨牌排列？如果存在，最少需要排列多少张骨牌？

给你 $T$ 个测试用例，求解每个测试用例的问题。

in:
3
4
1 3 2 5
2
1 100
10
298077099 766294630 440423914 59187620 725560241 585990757 965580536 623321126 550925214 917827435

out:
4
-1
3

*/

#include <bits/stdc++.h>
using namespace std;

long long sn[200005];

long long main(){
    long long T;
    cin >> T;
    while(T--){
        long long n;
        cin >> n;
        long long last_card, card_cnts;
        for (long long i = 1; i <= n;i++){
            cin >> sn[i];
        }
        long long begs = sn[1], ends = sn[n];
        last_card = sn[1];
        card_cnts = 2;
        if(begs==ends){
            cout<< 2 << '\n';
            continue;
        }
        sort(sn + 1, sn + 1 + n);
        bool flag = true;
        for (long long i = 1; i <= n;i++){
            if(sn[i]==begs){
                continue;
            }
            if(sn[i]==ends){
                if(sn[i]>2*last_card){
                    flag = false;
                }
                break;
            }
            if(sn[i+1]>2*last_card){
                last_card = sn[i];
                card_cnts++;
                if(sn[i+1]>2*last_card){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            cout << card_cnts << '\n';
        }else{
            cout << -1 << '\n';
        }
    }
}