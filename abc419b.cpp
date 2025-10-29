#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main(){
    int Q;
    cin>>Q;
    while (Q--) {
        int opt, x;
        cin >> opt;
        if (opt == 1) {
            cin >> x;
            q.push(x);
        }else{
            if(!q.empty()){
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }
}