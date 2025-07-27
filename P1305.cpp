#include <bits/stdc++.h>
using namespace std;

struct tree{
    char lc;
	char rc;
};

map <char, tree> a;

void dfs(char r){
    if(r=='*'){
        return;
    }
    cout << r;
    dfs(a[r].lc);
    dfs(a[r].rc);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    char begin;
    cin >> begin;
    cin >> a[begin].lc;
    cin >> a[begin].rc;
    for (int i=1; i < n; i++){
        char tmp;
        cin >> tmp;
        cin >> a[tmp].lc;
        cin >> a[tmp].rc;
    }
    dfs(begin);
    return 0;
}