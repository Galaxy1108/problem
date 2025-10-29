#include <bits/stdc++.h>
using namespace std;

char maps[1005][1005];

int main(){
    long long h, w;
    cin >> h >> w;
    long long minx = LLONG_MAX, miny = LLONG_MAX, maxx = LLONG_MIN, maxy = LLONG_MIN;
    for (long long i = 0; i < h;i++){
        for (long long j = 0; j < w;j++){
            cin >> maps[i][j];
            if(maps[i][j]=='#'){
                minx = min(minx, i);
                maxx = max(maxx, i);
                miny = min(miny, j);
                maxy = max(maxy, j);
            }
        }
    }
    for (long long i = minx; i <= maxx;i++){
        for (long long j = miny; j <= maxy;j++){
            if(maps[i][j]=='.'){
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}