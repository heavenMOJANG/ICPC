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
ll n,na,nb,a[210],b[210],g[5][5],suma,sumb,lcm;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    g[0][0]=0; g[0][1]=-1;g[0][2]=1; g[0][3]=1; g[0][4]=-1;
    g[1][0]=1; g[1][1]=0; g[1][2]=-1;g[1][3]=1; g[1][4]=-1;
    g[2][0]=-1;g[2][1]=1; g[2][2]=0; g[2][3]=-1;g[2][4]=1;
    g[3][0]=-1;g[3][1]=-1;g[3][2]=1; g[3][3]=0; g[3][4]=1;
    g[4][0]=1; g[4][1]=1; g[4][2]=-1;g[4][3]=-1;g[4][4]=0;
    cin>>n>>na>>nb;
    for(ll i=1;i<na;++i) cin>>a[i];cin>>a[0];
    for(ll i=1;i<nb;++i) cin>>b[i];cin>>b[0];
    lcm=na*nb/__gcd(na,nb);
    for(ll i=1;i<=lcm;++i){
        ll x=a[i%na],y=b[i%nb];
        if(g[x][y]==1) suma++;
        if(g[x][y]==-1) sumb++;
    }
    suma*=n/lcm;
    sumb*=n/lcm;
    n%=lcm;
    for(ll i=1;i<=n;++i){
        ll x=a[i%na],y=b[i%nb];
        if(g[x][y]==1) suma++;
        if(g[x][y]==-1) sumb++;
    }
    cout<<suma<<" "<<sumb;
    return 0;
}