#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
struct Node{ll v,x;}a[20010];
ll n,sum;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].v>>a[i].x;
    for(ll i=1;i<n;++i)
        for(ll j=i+1;j<=n;++j)
            sum+=max(a[i].v,a[j].v)*llabs(a[i].x-a[j].x);
    cout<<sum;
    return 0;
}
