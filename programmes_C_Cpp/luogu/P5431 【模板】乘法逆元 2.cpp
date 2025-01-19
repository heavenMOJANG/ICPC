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
const ll N=5000010;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll n,p,k,sum,a[N],s[N],t[N];
ll fast_power(ll a,ll x){
    ll res=1;
    while(x){
        if(x&1) res=res*a%p;
        a=a*a%p;
        x>>=1;
    }
    return res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>p>>k;
    s[0]=1;
    for(ll i=1;i<=n;++i) cin>>a[i],s[i]=s[i-1]*a[i]%p;
	t[n]=fast_power(s[n],p-2);
	for(ll i=n-1;i>=1;--i) t[i]=t[i+1]*a[i+1]%p;
	for(ll i=n;i>=1;--i) sum=(sum+(t[i]*s[i-1])%p)*k%p;
    cout<<sum;
    return 0;
}