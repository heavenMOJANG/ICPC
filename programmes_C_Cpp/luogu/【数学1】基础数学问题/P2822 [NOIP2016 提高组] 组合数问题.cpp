#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll t,k,n,m,f[2010][2010],s[2010][2010];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t>>k;
    for(ll i=0;i<=2000;++i) f[i][i]=f[i][0]=1;
    for(ll i=1;i<=2000;++i)
        for(ll j=1;j<i;++j) f[i][j]=(f[i-1][j-1]+f[i-1][j])%k;
    for(ll i=1;i<=2000;i++)
        for(ll j=1;j<=2000;j++){
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1];
            if(f[i][j]==0&&j<=i) s[i][j]++;
        }
    while(t--){
        cin>>n>>m;
        cout<<s[n][m]<<"\n";
    }
    return 0;
}