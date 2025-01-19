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
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
struct Node{
    string name;
    ll id,sum;
}a[1010];
ll n,m,x,idx;
map<string,ll>mp,g;
string s;
ll cmp(Node x,Node y){return x.id<y.id;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i){
        cin>>s>>x;
        mp[s]=x;
        g[s]=i;
    }
    for(ll i=1;i<=m;++i){
        ll k;cin>>k;
        for(ll j=1;j<=k;++j) cin>>s>>x,mp[s]-=x;
    }
    for(auto it=mp.begin();it!=mp.end();++it){
        if(it->second<0) return puts("NO\n"),0;
        if(it->second==0) continue;
        a[++idx]={it->first,g[it->first],it->second};
    }
    sort(a+1,a+1+idx,cmp);
    cout<<"YES\n";
    for(ll i=1;i<=idx;++i){
        cout<<a[i].name<<" "<<a[i].sum<<"\n";
    }
    return 0;
}