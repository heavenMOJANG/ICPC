#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
const ll inf=0x3f3f3f3f;
using namespace std;
ll n,l,r,g[110][110],w[110],sum,minn=LLONG_MAX;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(g,inf,sizeof(g));
    cin>>n;
    for(ll i=1;i<=n;++i){
        g[i][i]=0;
        cin>>w[i]>>l>>r;
        g[i][l]=g[l][i]=(l>0);
        g[i][r]=g[r][i]=(r>0);
    }
    for(ll k=1;k<=n;++k)
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    for(ll i=1;i<=n;++i){
		sum=0;
		for(ll j=1;j<=n;++j) sum+=g[i][j]*w[j];
		minn=min(minn,sum);
	}
    cout<<minn<<"\n";
    return 0;
}