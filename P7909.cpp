#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(b/a==c/a){
		cout<<c%a;
	}else{
		cout<<a-1;
	}
	return 0;
}