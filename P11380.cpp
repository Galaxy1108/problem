#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long fat[200005];
long long get_father(long long a){
    return (fat[a] == a ? a : fat[a] = get_father(fat[a]));
}
void merge(long long a,long long b){
    long long father_a = get_father(a), father_b = get_father(b);
    if(father_a!=father_b){
        fat[father_a] = father_b;
    }
}
set<long long> p;
long long in[1005];
map<pair<long long, long long>, bool> mp;

int main(){
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i <= n;i++){
        fat[i] = i;
    }
    for (long long i = 1; i <= m;i++){
        long long a, b;
        cin >> a >> b;
        if(mp[{a,b}]){
            continue;
        }
        if(a==get_father(b)){
            cout << 0;
            return 0;
        }
        merge(a, b);
        in[b]++;
        if(in[b]>1){
            cout << 0;
            return 0;
        }
        mp[{a, b}] = true;
    }
    for (long long i = 1; i <= n;i++){
        p.insert(get_father(i));
    }
    long long si = p.size();
    long long anss = 1;
    for (long long i = 1; i <= si;i++){
        anss = (anss * i) % mod;
    }
    cout << anss;
}