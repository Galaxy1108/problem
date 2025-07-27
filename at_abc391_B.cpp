#include <bits/stdc++.h>
using namespace std;

char S[55][55], T[55][55];

long long main(){
    long long n,m;
    cin >> n >> m;
    for (long long i = 1; i <= n;i++){
        for (long long j = 1; j <= n;j++){
            cin >> S[i][j];
        }
    }
    for (long long i = 1; i <= m;i++){
        for (long long j = 1; j <= m;j++){
            cin >> T[i][j];
        }
    }
    for (long long a = 1; a+m-1 <= n;a++){
        for (long long b = 1; b+m-1 <= n;b++){
            bool flag = true;
            for (long long Si = a; Si - a + 1 <= m && flag;Si++){
                for (long long Sj = b; Sj - b + 1 <= m;Sj++){
                    long long Ti = Si - a + 1, Tj = Sj - b + 1;
                    if(S[Si][Sj]!=T[Ti][Tj]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                cout << a << ' ' << b;
                return 0;
            }
        }
    }
    return 1;
}