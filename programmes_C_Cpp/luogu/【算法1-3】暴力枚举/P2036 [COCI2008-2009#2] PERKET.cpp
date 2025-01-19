#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s[11],b[11],vis[11],ss=1,bb,minn=LLONG_MAX;
void dfs(ll x){
	if(x==n+1) return;
	else
		for(ll i=1;i<=n;++i)
			if(!vis[i]){
				ss*=s[i];
				bb+=b[i];
				vis[i]=1;
				minn=min(minn,abs(ss-bb));
				dfs(i+1);
				ss/=s[i];
				bb-=b[i];
				vis[i]=0;
			}
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>s[i]>>b[i];
    dfs(1);
    cout<<minn;
    return 0;
}