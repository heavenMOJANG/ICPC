#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int a[N];
int main(){
    freopen("10.in", "r", stdin);
    freopen("10.out", "w", stdout);
	int n,p;
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	p=p%n;
	reverse(a+1,a+n+1);
	reverse(a+1,a+n-p+1);
	reverse(a+n-p+1,a+n+1);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
