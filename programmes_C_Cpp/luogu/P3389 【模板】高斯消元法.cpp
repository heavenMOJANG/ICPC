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
double a[110][110],eps=1e-7;
ll n;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n+1;++j) cin>>a[i][j];
    for(ll i=1;i<=n;++i){
        ll maxn=i;
        for(ll j=i+1;j<=n;++j) if(fabs(a[j][i])>fabs(a[maxn][i])) maxn=j;
        if(fabs(a[i][i])<eps){cout<<"No Solution\n";return 0;}
        for(ll j=n+1;j>=1;--j) a[i][j]=a[i][j]/a[i][i];
        for(ll j=1;j<=n;++j)
            if(j!=i){
                double tmp=a[j][i]/a[i][i];
                for(ll k=1;k<=n+1;++k) a[j][k]-=a[i][k]*tmp;
            }
    }
    for(ll i=1;i<=n;++i) cout<<fixed<<setprecision(2)<<a[i][n+1]<<"\n";
    return 0;
}