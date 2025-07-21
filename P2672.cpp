#include <bits/stdc++.h>
using namespace std;

struct f{
	long long z, p;
};

bool cmp(f a,f b){
	return a.p > b.p;
}

long long ps[1000000], qs[1000000], hs[1000000];

int main(){
	long long n;
	cin >> n;
	f sn[n];
	for (long long i = 0; i < n;i++){
		cin >> sn[i].z;
	}
	for (long long i = 0; i < n;i++){
		cin >> sn[i].p;
	}
	sort(sn, sn + n, cmp);
	//long long ps[n + 1] = {};
	for (long long i = 1; i <= n;i++){
		ps[i] = ps[i - 1] + sn[i - 1].p;
	}
//	long long qs[n + 1] = {};
	for (long long i = 1; i <= n;i++){
		qs[i] = max(qs[i - 1], sn[i - 1].z * 2);
	}
	//long long hs[n + 1] = {};
	for (long long i = n; i >= 1;i--){
		hs[i] = max(hs[i + 1], sn[i - 1].z * 2 + sn[i - 1].p);
	}
	for (long long i = 1; i <= n;i++){
		cout << max(ps[i] + qs[i], ps[i - 1] + hs[i]) << endl;
	}
	return 0;
}