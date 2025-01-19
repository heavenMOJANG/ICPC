#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
string s[25];
ll n,g[25][25],h[25],res;
char c;
void dfs(string st,ll pre){
	res=max(res,(ll)st.size());
	h[pre]++;
	for(ll i=0;i<n;++i) if(g[pre][i]&&h[i]<2) dfs(st+s[i].substr(g[pre][i]),i);
	h[pre]--;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
	for(ll i=0;i<n;++i) cin>>s[i];
	cin>>c;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;++j){
			string a=s[i],b=s[j];
			for(ll k=1;k<min(a.size(),b.size());++k) if(a.substr(a.size()-k,k)==b.substr(0,k)){g[i][j]=k;break;}
		}
	for (ll i=0;i<n;++i) if(s[i][0]==c) dfs(s[i],i);
    cout<<res;
    return 0;
}