#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f;
ll n,m,k,l,r,a[100010],nxt[100010];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i],nxt[i]=i+1;
    cin>>m;
    while(m--){
        cin>>k>>l>>r;
        if(l>r) swap(l,r);
        if(k){
            ll res=0;
            for(ll i=l;i<=r;i=nxt[i]){
				res+=a[i];
				while(a[nxt[i]]==1) nxt[i]=nxt[nxt[i]];
				if(nxt[i]>r){res+=r-i;break;}
				if(nxt[i]!=i+1) res+=(nxt[i]-1)-i;
			}
            cout<<res<<"\n";
        }
        else
            for(ll i=l;i<=r;i=nxt[i]){
				if(a[i]>1) a[i]=sqrt(a[i]);
				while(a[nxt[i]]==1) nxt[i]=nxt[nxt[i]];
			}
    }
    return 0;
}
