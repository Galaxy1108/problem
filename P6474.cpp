/**
 * @name 荆轲刺秦王
 * @link https://www.luogu.com.cn/problem/P6474
 * @test 2025/10/18 T2
 * @class blue
 * @date 2025/10/18 周六 11:50
 * @par tags
 * #搜索
 */

#include <bits/stdc++.h>
using namespace std;

// #define LOCAL

using namespace std;
namespace ly
{
    namespace IO
    {
        #ifndef LOCAL
            constexpr auto maxn=1<<20;
            char in[maxn],out[maxn],*p1=in,*p2=in,*p3=out;
            #define getchar() (p1==p2&&(p2=(p1=in)+fread(in,1,maxn,stdin),p1==p2)?EOF:*p1++)
            #define flush() (fwrite(out,1,p3-out,stdout))
            #define putchar(x) (p3==out+maxn&&(flush(),p3=out),*p3++=(x))
            class Flush{public:~Flush(){flush();}}_;
        #endif
        namespace usr
        {
            template<typename type>
            inline type read(type &x)
            {
                x=0;bool flag(0);char ch=getchar();
                while(!isdigit(ch)) flag^=ch=='-',ch=getchar();
                while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
                return flag?x=-x:x;
            }
            template<typename type>
            inline void write(type x)
            {
                x<0?x=-x,putchar('-'):0;
                static short Stack[50],top(0);
                do Stack[++top]=x%10,x/=10;while(x);
                while(top) putchar(Stack[top--]|48);
            }
            inline char read(char &x){do x=getchar();while(isspace(x));return x;}
            inline char write(const char &x){return putchar(x);}
            inline void read(char *x){static char ch;read(ch);do *(x++)=ch;while(!isspace(ch=getchar())&&~ch);}
            template<typename type>inline void write(type *x){while(*x)putchar(*(x++));}
            inline void read(string &x){static char ch;read(ch),x.clear();do x+=ch;while(!isspace(ch=getchar())&&~ch);}
            inline void write(const string &x){for(int i=0,len=x.length();i<len;++i)putchar(x[i]);}
            template<typename type,typename...T>inline void read(type &x,T&...y){read(x),read(y...);}
            template<typename type,typename...T>
            inline void write(const type &x,const T&...y){write(x),putchar(' '),write(y...),sizeof...(y)^1?0:putchar('\n');}
            template<typename type>
            inline void put(const type &x,bool flag=1){write(x),flag?putchar('\n'):putchar(' ');}
        }
        #ifndef LOCAL
            #undef getchar
            #undef flush
            #undef putchar
        #endif
    }using namespace IO::usr;
}using namespace ly::IO::usr;

int tags[355][355];
bool tags2[355][355];

struct p_2d {
    int x, y, w, ys_c, sy_c;
};

struct ans_p {
    int w, ys_c, sy_c;
    friend bool operator>(ans_p a, ans_p b) {
        return ((a.w == b.w) ? ((a.ys_c + a.sy_c == b.ys_c + b.sy_c) ? (a.sy_c > b.sy_c) : (a.ys_c + a.sy_c > b.ys_c + b.sy_c)) : (a.w > b.w));
    }
    friend bool operator<(ans_p a, ans_p b) {
        return ((a.w == b.w) ? ((a.ys_c + a.sy_c == b.ys_c + b.sy_c) ? (a.sy_c < b.sy_c) : (a.ys_c + a.sy_c < b.ys_c + b.sy_c)) : (a.w < b.w));
    }
};

ans_p anss[355][355];
bool vis[355][355][20][20];
queue<p_2d> q;
int n, m, c1, c2, d;

int f[9][2] = { {INT_MAX,INT_MAX},{1,0},{-1,0},{0,1},{0,-1},{1,-1},{-1,1},{-1,-1},{1,1} };

inline bool check(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int main() {
    read(n, m, c1, c2, d);
    int sx, sy, tx, ty;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m;j++) {
            string str;
            read(str);
            if (str == ".") {
                continue;
            }
            if (str == "S") {
                sx = i, sy = j;
                continue;
            }
            if (str == "T") {
                tx = i, ty = j;
                continue;
            }
            int dis_max = atoi(str.c_str()) - 1;
            tags2[i][j] = true;
            for (int dis = 0;dis <= dis_max;dis++) {
                if (i + dis <= n) {
                    int y_dis = dis_max - dis;
                    if (j + y_dis + 1 <= m) {
                        tags[i + dis][j + y_dis + 1]--;
                    }
                    if (j - y_dis >= 1) {
                        tags[i + dis][j - y_dis]++;
                    } else {
                        tags[i + dis][0]++;
                    }
                }
                if (i - dis >= 1 && dis != 0) {
                    int y_dis = dis_max - dis;
                    if (j + y_dis + 1 <= m) {
                        tags[i - dis][j + y_dis + 1]--;
                    }
                    if (j - y_dis >= 1) {
                        tags[i - dis][j - y_dis]++;
                    } else {
                        tags[i - dis][0]++;
                    }
                }
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            tags[i][j] += tags[i][j - 1];
            anss[i][j].w = INT_MAX;
        }
    }
    q.push({ sx,sy,0,0,0 });
    anss[sx][sy] = { 0,0,0 };
    vis[sx][sy][0][0] = true;
    while (!q.empty()) {
        p_2d u = q.front();
        q.pop();
        for (int i = 1;i <= 8;i++) {
            int vx = u.x + f[i][0], vy = u.y + f[i][1];
            if (!(!check(vx, vy) || tags2[vx][vy] || u.ys_c + !!(tags[vx][vy]) > c1 || vis[vx][vy][u.ys_c + !!(tags[vx][vy])][u.sy_c])) {
                anss[vx][vy] = min(anss[vx][vy], (ans_p) { u.w + 1, u.ys_c + !!(tags[vx][vy]), u.sy_c });
                vis[vx][vy][u.ys_c + !!(tags[vx][vy])][u.sy_c] = true;
                q.push({ vx,vy,u.w + 1, u.ys_c + !!(tags[vx][vy]), u.sy_c });
            }
            vx = u.x + d * f[i][0], vy = u.y + d * f[i][1];
            if (i <= 4 && !(!check(vx, vy) || tags2[vx][vy] || u.ys_c + !!(tags[vx][vy]) > c1 || u.sy_c + 1 > c2 || vis[vx][vy][u.ys_c + !!(tags[vx][vy])][u.sy_c + 1])) {
                anss[vx][vy] = min(anss[vx][vy], (ans_p) { u.w + 1, u.ys_c + !!(tags[vx][vy]), u.sy_c + 1 });
                vis[vx][vy][u.ys_c + !!(tags[vx][vy])][u.sy_c + 1] = true;
                q.push({ vx,vy,u.w + 1, u.ys_c + !!(tags[vx][vy]), u.sy_c + 1 });
            }
        }
    }
    if (anss[tx][ty].w == INT_MAX) {
        write(-1);
        return 0;
    }
    write(anss[tx][ty].w, anss[tx][ty].ys_c, anss[tx][ty].sy_c);
}