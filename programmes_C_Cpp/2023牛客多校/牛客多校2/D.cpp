#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,m,k,a[2010][2010],vis[2010];
ll getMax(ll x){
    ll cur=-1,res=0;
    for(ll i=0;i<m;++i){
        if(vis[i]) continue;
        if(cur<a[x][i]) cur=a[x][i],res=i;
    }
    return res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>_;
    while(_--){
        memset(vis,0,sizeof(vis));
        vector<ll>ans;
        cin>>n>>m>>k;
        for(ll i=0;i<n;++i)
            for(ll j=0;j<m;++j) cin>>a[i][j];
        for(ll i=0,p=(k-1)%n;i<k;++i,--p){
            if(p<0) p=n-1;
            ll maxn=getMax(p);
            vis[maxn]=1;
            ans.push_back(maxn+1);
        }
        sort(ans.begin(),ans.end());
        for(ll i=0;i<ans.size();++i) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
