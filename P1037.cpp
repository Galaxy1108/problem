/**
 * problem: [NOIP 2002 普及组] 产生数
 * link: https://www.luogu.com.cn/problem/P1037
 * difficult: yellow
 * date: 2025/10/28 周二 20:02
 * tags: #图论
 */

#include<bits/stdc++.h>
using namespace std;

bool can_to[10][10];
__int128_t to_cnt[10];

vector<__int128_t> a[10];

queue<__int128_t> q;

void print_i128(__int128_t n){
    if(n<10){
        cout<<(long long)n;
        return;
    }
    print_i128(n/10);
    cout<<(long long)(n%10);
}

void write_i128(__int128_t &num){
    __int128_t n=0;
    char c;
    cin>>c;
    while(isdigit(c)){
        n = n*10+c-'0';
        c = getchar();
    }
    num = n;
}

int main(){
    __int128_t n,k;
    write_i128(n),write_i128(k);
    for(__int128_t i=1;i<=k;i++){
        __int128_t x,y;
        write_i128(x),write_i128(y);
        a[x].emplace_back(y);
    }
    for(__int128_t i=0;i<=9;i++){
        q.push(i);
        while(!q.empty()){
            __int128_t u = q.front();
            q.pop();
            for(auto v:a[u]){
                if(can_to[i][v]){
                    continue;
                }
                can_to[i][v]=true;
                q.push(v);
            }
        }
        can_to[i][i]=true;
        for(__int128_t j=1;j<=9;j++){
            if(can_to[i][j]){
                to_cnt[i]++;
            }
        }
        to_cnt[i]+=(i==0);
    }
    __int128_t ans=1;
    while(n){
        ans *= to_cnt[n%10];
        n/=10;
    }
    print_i128(ans);
}
