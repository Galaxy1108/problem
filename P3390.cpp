// matrix

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

struct matrix{
    int n, m;
    long long nums[105][105];
    matrix(int t_n, int t_m) : n(t_n), m(t_m){};
    void in(int t_n,int t_m){
        this->n = t_n;
        this->m = t_m;
        for (int i = 1; i <= t_n;i++){
            for (int j = 1; j <= t_m;j++){
                cin >> this->nums[i][j];
            }
        }
    }
    friend istream& operator>>(istream& in,matrix& a){
        for (int i = 1; i <= a.n;i++){
            for (int j = 1; j <= a.m;j++){
                in >> a.nums[i][j];
            }
        }
        return in;
    }
    friend ostream& operator<<(ostream& out,matrix a){
        for (int i = 1; i <= a.n;i++){
            for (int j = 1; j <= a.m;j++){
                out << a.nums[i][j] << " \n"[j == a.m];
            }
        }
        return out;
    }
    void clean(){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= m;j++){
                nums[i][j] = 0;
            }
        }
    }
    void E(){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= m;j++){
                nums[i][j] = (i == j);
            }
        }
    }
    friend matrix operator*(matrix a,matrix b){
        if(a.m!=b.n){
            matrix anss(-1, -1);
            return anss;
        }
        matrix anss(a.n, b.m);
        anss.clean();
        for (int i = 1; i <= a.n;i++){
            for (int j = 1; j <= b.m;j++){
                for (int k = 1; k <= a.m;k++){
                    anss.nums[i][j] += a.nums[i][k] * b.nums[k][j];
                    anss.nums[i][j] %= MOD;
                }
            }
        }
        return anss;
    }
    friend matrix operator%(matrix a,long long mod){
        matrix anss = a;
        for (int i = 1; i <= anss.n;i++){
            for (int j = 1; j <= anss.m;j++){
                a.nums[i][j] %= mod;
            }
        }
        return anss;
    }
    friend matrix operator^(matrix a,long long k){
        matrix anss(a.n, a.m);
        anss.E();
        while(k){
            if(k&1){
                anss = (anss * a) % MOD;
            }
            a = (a * a) % MOD;
            k >>= 1;
        }
        return anss;
    }
};

int main(){
    long long n, k;
    cin >> n >> k;
    matrix A(n, n);
    cin >> A;
    A = (A ^ k);
    cout << A;
}