#include <bits/stdc++.h>
using namespace std;

int n,m,ans=INT_MAX;

void seach(int i,int ri,int hi,int e_vi,int this_s){
	//cout<<i<<" "<<ri<<" "<<hi<<" "<<e_vi<<" "<<this_s<<endl;
	if(i==m && e_vi==0){
		ans=min(ans,this_s);
		return;
	}
	if(i>m || e_vi<=0){
		return;
	}
	if(this_s>=ans){
		return;
	}
	long long tmp=0;
	for(int j=1;j<=m-i;j++){
	    tmp+=j*j*j;
	}
	if(e_vi<tmp){
	    return;
	}
	tmp=0;
	for(int j=1;j<=m-i;j++){
		tmp+=(ri-j)*(ri-j)*(hi-j);
	} 
	if(e_vi>tmp){
		return;
	}
	for(int thi=hi-1;thi>=m-i;thi--){
		for(int tri=ri-1;tri>=m-i;tri--){
		    if(tri==0){
		        continue;
		    }
			if(e_vi-tri*tri*thi<0 || (this_s+2*e_vi/tri)>=ans){
				continue;
			} 
			seach(i+1,tri,thi,e_vi-tri*tri*thi,this_s+2*tri*thi);
		}
	}
}

int main(){
	//int n,m;
	cin>>n>>m;
	for(int tri=m;tri<=sqrt(n);tri++){
		for(int thi=m;thi<=n;thi++){
			if(n-tri*tri*thi<0){
				continue;
			}
			seach(1,tri,thi,n-tri*tri*thi,2*tri*thi+tri*tri);
		}
	} 
	if(ans==INT_MAX){
	    cout<<0;
	    return 0;
	}
	cout<<ans<<endl;
	return 0;
} 