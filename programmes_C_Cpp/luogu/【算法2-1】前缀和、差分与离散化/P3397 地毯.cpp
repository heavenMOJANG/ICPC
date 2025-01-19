#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll n,m,d[1010][1010];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;++i){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        d[x1][y1]++;
        d[x2+1][y2+1]++;
        d[x1][y2+1]--;
        d[x2+1][y1]--;
    }
    for(ll i=1;i<=n;++i){
        for(ll j=1;j<=n;++j) cout<<(d[i][j]+=d[i][j-1]+d[i-1][j]-d[i-1][j-1])<<" ";
        cout<<"\n";
    }
    
    return 0;
}