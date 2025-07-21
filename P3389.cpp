#include <bits/stdc++.h>
using namespace std;

long double sn[105][105];
#define eps 1e-9

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n + 1;j++){
            cin >> sn[i][j];
        }
    }
    for (int this_x = 1; this_x <= n ;this_x++){
        int max_i = this_x;
        for (int i = this_x + 1; i <= n;i++){
            if(abs(sn[max_i][this_x])<abs(sn[i][this_x])){
                max_i = i;
            }
        }
        if(abs(sn[max_i][this_x])<eps){
            cout << "No Solution";
            return 0;
        }
        swap(sn[max_i], sn[this_x]);
        // for (int j = this_x; j <= n + 1;j++){
        //     swap(sn[max_i][j], sn[this_x][j]);
        // }
        for (int j = this_x + 1; j <= n + 1;j++){
            sn[this_x][j] /= sn[this_x][this_x];
        }
        sn[this_x][this_x] = 1;
        for (int i = this_x + 1; i <= n;i++){
            if(abs(sn[i][this_x])<eps){
                continue;
            }
            for (int j = this_x + 1; j <= n + 1;j++){
                sn[i][j] -= sn[this_x][j] * sn[i][this_x];
            }
            sn[i][this_x] -= sn[this_x][this_x] * sn[i][this_x];
        }
        // for (int i = 1; i <= n;i++){
        //     for (int j = 1; j <= n + 1;j++){
        //         cout << sn[i][j] << "\t\n"[j == n + 1];
        //     }
        // }
    }
    for (int i = n - 1; i >= 1;i--){
        for (int j = n; j > i;j--){
            sn[i][n + 1] -= sn[i][j] * sn[j][n + 1];
        }
    }
    for (int i = 1; i <= n;i++){
        printf("%.2Lf\n", sn[i][n + 1]);
    }
}