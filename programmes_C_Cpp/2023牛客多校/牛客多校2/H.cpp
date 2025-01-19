#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll n,q,f[200010],c[200010],ans,l,r;
string s,x;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q>>s;s=" "+s;
    for(ll i=1;i<=n;++i)
        if(s[i]=='A') f[i]=-f[i-1]-1,c[i]=c[i-1]+1;
        else f[i]=f[i-1]+1,c[i]=c[i-1];
    while(q--){
        cin>>l>>r>>x;x=" "+x;
        l=(ans^l)%n+1,r=(ans^r)%n+1;
        if(l>r) swap(l,r);
        ll tmp=0;
        for(ll i=1;i<x.size();++i) tmp=2LL*tmp+x[i]-'0';
        ll mod=1<<x.size()-1;
        if((c[r]-c[l-1])%2) ans=f[r]+f[l-1],tmp=-tmp;
		else ans=f[r]-f[l-1];
		ans=((tmp+ans)%mod+mod)%mod;
        for(ll i=1;i<x.size();++i) cout<<((ans&(1LL<<x.size()-i-1))?1:0);
        cout<<"\n";
    }
    return 0;
}
