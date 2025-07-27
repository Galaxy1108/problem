#include <bits/stdc++.h>
using namespace std;

string strs[15];
string s[100005];
int n, k, x, cnts;

string str;

void dfs(int I){
    if(I==k+1){
        s[++cnts] = str;
        return;
    }
    for (int i = 1; i <= n;i++){
        string tstr = str;
        str += strs[i];
        dfs(I + 1);
        str = tstr;
    }
}

int main(){
    cin >> n >> k >> x;
    for (int i = 1; i <= n;i++){
        cin >> strs[i];
    }
    dfs(1);
    sort(s + 1, s + 1 + cnts);
    cout << s[x];
}