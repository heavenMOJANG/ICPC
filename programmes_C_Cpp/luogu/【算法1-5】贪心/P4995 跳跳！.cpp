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
ll n,a[310],res;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n);
    res+=a[n]*a[n];
    for(ll l=1,r=n;l<r;){
        res+=(a[r]-a[l])*(a[r]-a[l]);r--;
        res+=(a[r]-a[l])*(a[r]-a[l]);l++;
    }
    cout<<res;
    return 0;
}