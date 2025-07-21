#include <bits/stdc++.h>
using namespace std;

struct big_int{
    int nums[45], size;
    big_int(){
        size = 0;
        for (int i = 0; i < 45;i++){
            nums[i] = 0;
        }
    }
    void operator=(int b){
        this->size = 0;
        while(b){
            this->nums[++this->size] = b % 10;
            b /= 10;
        }
    }
    friend big_int operator+(big_int a,big_int b){
        if(a.size>b.size){
            swap(a, b);
        }
        int add = 0;
        big_int anss;
        for (int i = 1; i <= b.size;i++){
            anss.nums[i] = a.nums[i] + b.nums[i] + add;
            add = anss.nums[i] / 10;
            anss.nums[i] %= 10;
        }
        anss.size = b.size;
        if(add){
            anss.nums[++anss.size] = add;
        }
        return anss;
    }
    friend big_int operator*(big_int a,int b){
        int add = 0;
        big_int anss;
        for (int i = 1; i <= a.size;i++){
            anss.nums[i] = (a.nums[i] * b + add);
            add = anss.nums[i] / 10;
            anss.nums[i] %= 10;
        }
        anss.size = a.size;
        while(add){
            anss.nums[anss.size + 1] = add;
            add = anss.nums[anss.size + 1] / 10;
            anss.nums[anss.size++] %= 10;
        }
        return anss;
    }
    friend big_int operator*(big_int a,big_int b){
        big_int anss;
        for (int i = b.size; i >= 1;i--){
            anss = (anss * 10 + a * b.nums[i]);
        }
        return anss;
    }
    friend bool operator<(big_int a,big_int b){
        if(a.size<b.size){
            return true;
        }
        if(a.size>b.size){
            return false;
        }
        for (int i = a.size; i >= 1;i--){
            if(a.nums[i]<b.nums[i]){
                return true;
            }
            if(a.nums[i]>b.nums[i]){
                return false;
            }
        }
        return false;
    }
    big_int subint(int l,int r){
        big_int anss;
        bool flag = true;
        anss.size = r - l + 1;
        for (int i = r; i >= l;i--){
            if(flag && !(this->nums[i])){
                continue;
            }
            flag = false;
            anss.nums[i - l + 1] = this->nums[i];
        }
        if(flag){
            anss.size = 0;
        }
        return anss;
    }
}dp[45][10];

struct out_bigint{
    friend out_bigint operator<<(out_bigint s,big_int a){
        if(a.size==0){
            cout << 0;
            return s;
        }
        for (int i = a.size; i >= 1;i--){
            cout << a.nums[i];
        }
        return s;
    }
    template<typename _T>
    friend out_bigint operator<<(out_bigint s,_T a){
        cout << a;
        return s;
    }
}bout;

struct in_bigint{
    friend in_bigint operator>>(in_bigint s,big_int& a){
        string p;
        cin >> p;
        size_t sizes = p.size();
        a.size = 0;
        for (int i = sizes - 1; i >= 0;i--){
            a.nums[++a.size] = p[i] - '0';
        }
        return s;
    }
    template<typename _T>
    friend in_bigint operator>>(in_bigint s,_T& a){
        cin >> a;
        return s;
    }
}bin;

int main(){
    int n, k;
    cin >> n >> k;
    big_int s;
    bin >> s;
    for (int i = 1; i <= n;i++){
        dp[i][0] = s.subint(1, i);
        for (int j = 1; j <= min(i-1,k);j++){
            dp[i][j] = 0;
            for (int p = j; p < i;p++){
                dp[i][j] = max(dp[i][j], dp[p][j - 1] * s.subint(p + 1, i));
            }
        }
    }
    bout << dp[n][k];
}