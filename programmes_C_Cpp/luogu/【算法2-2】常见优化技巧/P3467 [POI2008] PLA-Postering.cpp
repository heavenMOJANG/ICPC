#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,d[250010],w[250010],s[250010],top,res;
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>d[i]>>w[i];
    for(ll i=1;i<=n;++i){
		res++;
		while(top!=0&&w[s[top]]>w[i]) top--;
		if(w[s[top]]==w[i]) res--;
		s[++top]=i;
	}
    cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
