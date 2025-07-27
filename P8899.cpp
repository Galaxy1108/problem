#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("sy.io","r", stdin);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int sum[m][n];
        int ans[m];
        for (int i = 0; i < m;i++){
            for (int j = 0; j < n;j++){
                char tmp;
                cin>>tmp;
                sum[i][j] = tmp - '0';
            }
            cin >> ans[i];
        }
        bool del[m]={false};
        bool falg=true;
        for (int cnt = 0; cnt < m;){
            int cnt2 = 0;
            for (int i=0;i<n;i++){
                int sum0 = -1, sum1 = -1;
                bool falg0 = true, falg1 = true;
                for (int j = 0; j < m;j++){
                    if(del[j]){
                        continue;
                    }
                    if(sum[j][i]==0 && sum0 == -1){
                        sum0 = ans[j];
                    }else if(sum[j][i] == 0 && sum0 != ans[j]){
                        falg0 = false;
                        break;
                    }
                }
                for (int j = 0; j < m;j++){
                    if(del[j]){
                        continue;
                    }
                    if(sum[j][i]==1 && sum1 == -1){
                        sum1 = ans[j];
                    }else if(sum[j][i] == 1 && sum1 != ans[j]){
                        falg1 = false;
                        break;
                    }
                }
                if(falg0){
                    for (int j = 0; j < m;j++){
                        if(sum[j][i]==0 && del[j]==0){
                            del[j] = true;
                            cnt++;
                            cnt2++;
                        }
                    }
                }
                if(falg1){
                    for (int j = 0; j < m;j++){
                        if(sum[j][i]==1 && del[j]==0){
                            del[j] = true;
                            cnt++;
                            cnt2++;
                        }
                    }
                }
            }
            if(cnt2==0){
                falg = false;
                break;
            }
        }
        if(falg){
            cout << "OK\n";
        }else{
            cout << "LIE\n";
        }
    }
}