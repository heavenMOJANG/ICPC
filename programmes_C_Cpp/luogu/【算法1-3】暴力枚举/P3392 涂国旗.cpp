#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll n,m,minn=LLONG_MAX;
char a[60][60];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j) cin>>a[i][j];
    for(ll i=1;i<=n-2;++i)     //用i和j表示第一块和第二块颜色的结束的区域，然后枚举所有可能
		for(ll j=i+1;j<=n-1;++j){
		    ll  res=0;
			for(ll k=1;k<=i;++k)
				for (ll l=1;l<=m;++l) if(a[k][l]!='W') res++;
			for(ll k=i+1;k<=j;++k)
				for(ll l=1;l<=m;++l) if(a[k][l]!='B') res++;
			for(ll k=j+1;k<=n;++k)
				for(ll l=1;l<=m;++l) if(a[k][l]!='R') res++;
			minn=min(minn,res);
		}
    cout<<minn;
    return 0;
}