#include <bits/stdc++.h>
using namespace std;
int main(void){
	long long n;
	long long l,r,m,ans=0;
	const long long inf = (long long)1e9;
	cin >> n;
	l=0;r=inf;
	while((l+1)<r){
		m=(l+r)/2;
		if((m*m*2)<=n)l=m;
		else r=m;
	}
	ans+=l;
	l=0;r=inf;
	while((l+1)<r){
		m=(l+r)/2;
		if((m*m*4)<=n)l=m;
		else r=m;
	}
	ans+=l;
	cout << ans << endl;
	return 0;
}