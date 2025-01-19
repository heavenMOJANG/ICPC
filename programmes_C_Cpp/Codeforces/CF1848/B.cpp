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
ll t,n,k;
vector<ll>v[200010];
map<ll,ll>mp[200010];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        ll ans=LLONG_MAX;
        cin>>n>>k;
        for(ll i=1;i<=k;++i) v[i].clear(),mp[i].clear();
        for(ll i=1,x;i<=n;++i) cin>>x,v[x].push_back(i);
        if(k==1){cout<<"0\n";continue;}
        for(ll i=1;i<=k;++i){
            if(!v[i].size()) continue;
            for(ll j=0;j<v[i].size();++j){
                if(j==0) mp[i][v[i][j]-1]++;
                else mp[i][v[i][j]-v[i][j-1]-1]++;
            }
            mp[i][n-v[i][v[i].size()-1]]++;
        }
        for(ll i=1;i<=k;++i){
            if(!mp[i].size()) continue;
            ll maxn=0,secn=0;
            for(auto it=mp[i].begin();it!=mp[i].end();++it) 
                if(it->first>maxn) secn=maxn,maxn=it->first;
            if(mp[i][maxn]>1) ans=min(ans,maxn);
            else ans=min(ans,max(maxn/2,secn));
        }
        
        cout<<ans<<"\n";
    }
    return 0;
}