#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> sta;
priority_queue<int> a;

int main(){
    int n;
    cin >> n;
    long long anss = 0;
    for (int i = 1; i <= n;i++){
        int a;
        cin >> a;
        int cnts = 1;
        while(!sta.empty() && sta.top().first<=a){
            if(sta.top().first==a){
                cnts += sta.top().second;
            }
            anss += sta.top().second;
            sta.pop();
        }
        anss += (!sta.empty() != 0);
        sta.push({a, cnts});
    }
    cout << anss;
    return 0;
}