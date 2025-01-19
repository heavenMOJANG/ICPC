#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,k,a[1000010],b[1000010];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=k;++i) cin>>a[i]>>b[i];
    sort(a+1,a+1+k);
    sort(b+1,b+1+k);
    ll num1=0,num2=0;
    for(int i=1;i<=k;++i){
        if(a[i]!=a[i+1]) num1++;
        if(b[i]!=b[i+1]) num2++;
    }
    cout<<n*n-(n-num1)*(n-num2)<<'\n';
    return 0;
}
