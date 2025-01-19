#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
string s;
ll n,m,g[30][30],dp[30],ind[30],res,head,tail,q[30];
void topSort(ll u){ 
	for(ll i=1;i<=n;++i)
	 	if(g[u][i]==1&&ind[i]){
	 	    ind[i]--;
	 	    dp[i]=max(dp[i],dp[u]+1);
	 	    res=max(res,dp[i]);
			if(!ind[i]) q[++tail]=i;
	 	}
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;++i){ 
		ll flag=1;
	    cin>>s; 
		ll u=s[0]-'A'+1,v=s[2]-'A'+1;
		g[u][v]=1;
		if(u==v){cout<<"Inconsistency found after "<<i<<" relations.";return 0;}
		memset(ind,0,sizeof(ind));
		for(ll j=1;j<=n;++j){
		    dp[j]=1;
		    for(ll k=1;k<=n;++k) ind[k]+=g[j][k];
		}
		res=head=tail=0;
	    for(ll j=1;j<=n;++j) if(!ind[j]) q[++tail]=j;
	    head=0;
	    while(head<tail) topSort(q[++head]);
	    if(res==n){
	    	cout<<"Sorted sequence determined after "<<i<<" relations: ";
	    	for(ll j=1;j<=n;++j) cout<<char(q[j]+64);
	    	cout<<".";
	    	return 0;
	    }
	    for(ll j=1;j<=n;++j) if(ind[j]) flag=0;
	    if(!flag){
	    	cout<<"Inconsistency found after "<<i<<" relations.";
	        return 0;
	    }
	}
	cout<<"Sorted sequence cannot be determined.";
    return 0;
}