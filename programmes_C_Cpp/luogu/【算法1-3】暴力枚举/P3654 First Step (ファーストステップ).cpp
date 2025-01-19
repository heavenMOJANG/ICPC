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
ll n,m,k,res;
char a[110][110];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j) cin>>a[i][j];
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j){
            if(a[i][j]=='#') continue;
            ll flag=1;
            for(ll y=1;y<=k;++y) if(j+y-1>m||a[i][j+y-1]!='.'){flag=0;break;}
            res+=flag;
            flag=1;
            for(ll x=1;x<=k;++x) if(i+x-1>n||a[i+x-1][j]!='.'){flag=0;break;}
            res+=flag;
        }
    cout<<(k==1?res/2:res);
    return 0;
}