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
ll n,m,c,g[1010][1010],maxn,px,py;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>c;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j){
            cin>>g[i][j];
            g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
        }
    for(ll i=1;(i+c-1)<=n;++i)
        for(ll j=1;(j+c-1)<=m;++j){
            ll x1=i,y1=j,x2=i+c-1,y2=j+c-1;
            ll sum=g[x2][y2]-g[x1-1][y2]-g[x2][y1-1]+g[x1-1][y1-1];
            if(sum>maxn) maxn=sum,px=i,py=j;
        }
    cout<<px<<" "<<py;
    return 0;
}