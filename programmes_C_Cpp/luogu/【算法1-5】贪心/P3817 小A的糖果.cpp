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
ll n,x,a[100010],res;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(ll i=1;i<=n;++i) cin>>a[i];
    if(a[1]>x){
        res+=a[1]-x;
        a[1]=x;
    }
    for(ll i=2;i<=n;++i)
        if(a[i]+a[i-1]>x){
            res+=a[i]+a[i-1]-x;
            a[i]=x-a[i-1];
        }
    cout<<res;
    return 0;
}