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
ll n,p,a[5000010],s[5000010],minn=LLONG_MAX;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>p;
    for(ll i=1;i<=n;++i) cin>>a[i],s[i]=a[i]-a[i-1];
    for(ll i=1,x,y,z;i<=p;++i){
        cin>>x>>y>>z;
        if(x>y) swap(x,y);
        s[x]+=z;
        s[y+1]-=z;
    }
    for(ll i=1;i<=n;++i){
        s[i]+=s[i-1];
        minn=min(minn,s[i]);
    }
    cout<<minn;
    return 0; 
}