#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
vector<ll>row[200010],col[200010],vis(200010,0);
ll n,m,k;
void solve(){
    cin>>n>>m>>k;
    for(ll i=1,u,v;i<=k;++i){
		cin>>u>>v;
		row[u].push_back(v);
		col[v].push_back(u);
	}
    ll r=n,c=m,flag=1;
	while(r>=1&&c>=1){
		ll maxr=-1,maxc=-1;
		for(ll i=0;i<row[r].size();++i) maxc=max(maxc,row[r][i]);
		for(ll i=0;i<col[c].size();++i) maxr=max(maxr,col[c][i]);
		if(maxr>r){c--;continue;}
		else if(maxc>c){r--;continue;}
		else{
			if(r==1&&c==1){flag=0;break;}
			r--,c--;
		}
	}
	if(flag==1) cout<<"Chaneka\n";
	else cout<<"Bhinneka\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
