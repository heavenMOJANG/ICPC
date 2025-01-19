#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x7fffffff;
ll _,n,cnt[1010],cost[1010],a,b,c,recipe[1010][1010],vis[1010];
void solve(){
    memset(recipe,-1,sizeof(recipe));
    cin>>n;
    for(ll i=0;i<n;++i) cin>>cost[i],cnt[i]=1;
    while(cin>>a>>b>>c) recipe[a][b]=recipe[b][a]=c;
    for(ll i=0;i<n-1;++i){
        ll tmp=inf,p;
        for(ll j=0;j<n;++j) if(!vis[j]&&cost[j]<tmp) tmp=cost[j],p=j;
        vis[p]=1;
        for(ll j=0;j<n;++j){
            if(vis[j]&&recipe[j][p]!=-1){
                if(cost[recipe[j][p]]>cost[j]+cost[p]){
                    cost[recipe[j][p]]=cost[j]+cost[p];
                    cnt[recipe[j][p]]=cnt[p]*cnt[j];
                }
                else if(cost[recipe[j][p]]==cost[j]+cost[p]) cnt[recipe[p][j]]+=cnt[j]*cnt[p]; 
            }
        }
    }
    cout<<cost[0]<<" "<<cnt[0];
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    _=1;
    while(_--) solve();
    return 0;
}