#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("10.in", "r", stdin);
    freopen("10.out", "w", stdout);
	int n,m,q;
	cin>>n>>m>>q;
	vector<int>a(n+1);
	vector<int>b(m+1);
	vector<int>c(q+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>c[i];
	}
	int i=1,j=1,k=1;
	int ans=0xfffffff;
	while(i<=n&&j<=m&&k<=q){
		int res=abs(a[i]-b[j])+abs(a[i]-c[k])+abs(b[j]-c[k]);
		if(res<ans)ans=res;
		if(a[i]<b[j]&&a[i]<c[k])i++;
		else if(b[j]<a[i]&&b[j]<c[k])j++;
		else k++;
	}
	cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
