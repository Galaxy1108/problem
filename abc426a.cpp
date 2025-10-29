#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main() {
    mp["Ocelot"] = 1;
    mp["Serval"] = 2;
    mp["Lynx"] = 3;
    string x, y;
    cin >> x >> y;
    cout << (mp[x] >= mp[y] ? "Yes" : "No");
}