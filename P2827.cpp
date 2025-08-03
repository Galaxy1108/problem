#include <bits/stdc++.h>
using namespace std;

template<typename T_,int N_>
struct queues{
    queue<T_> Q[N_];
    void push(T_ num,int idx){
        Q[idx].push(num);
    }
    optional<T_> top(int idx){
        return (Q[idx].empty() ? nullopt : Q[idx].front());
    }
    optional<T_> top_max(){
        T_ max_top = numeric_limits<T_>::min();
        for (int idx = 0; idx < N_;idx++){
            if(Q[idx].empty()){
                continue;
            }
            max_top = max(max_top, Q[idx].front());
        }
        return (max_top == numeric_limits<T_>::min() ? nullopt : (optional<T_>)max_top);
    }
    void pop(int idx){
        Q[idx].pop();
    }
    void pop_max(){
        T_ max_top = numeric_limits<T_>::min();
        int max_idx = -1;
        for (int idx = 0; idx < N_;idx++){
            if(Q[idx].empty()){
                continue;
            }
            if(max_top<Q[idx].front()){
                max_top = Q[idx].front();
                max_idx = idx;
            }
        }
        if(max_idx==-1){
            return;
        }
        Q[max_idx].pop();
    }
};

int sn[100005];
queues<int, 3> qs;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q, u, v, t;
    cin >> n >> m >> q >> u >> v >> t;
    for (int i = 0; i < n;i++){
        cin >> sn[i];
    }
    sort(sn, sn + n);
    for (int i = n - 1; i >= 0;i--){
        qs.push(sn[i], 0);
    }
    int add_l = 0;
    for (int T = 1; T <= m;T++){
        optional<int> r_maxs = qs.top_max();
        qs.pop_max();
        assert(r_maxs.has_value());
        int maxs = r_maxs.value() + add_l;
        int del_1 = 1ll * u * maxs / v, del_2 = maxs - del_1;
        del_1 -= add_l + q;
        del_2 -= add_l + q;
        qs.push(del_1,1);
        qs.push(del_2,2);
        add_l += q;
        if(!(T % t)){
            cout << maxs << ' ';
        }
    }
    cout << '\n';
    int cntt = 1;
    optional<int> r_maxs;
    while(r_maxs=qs.top_max(),r_maxs.has_value()){
        qs.pop_max();
        if(!(cntt % t)){
            cout << r_maxs.value() + add_l << ' ';
        }
        cntt++;
    }
    return 0;
}