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
ll w,n,p[30010],cnt,l,r;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>w>>n;
    for(ll i=1;i<=n;++i) cin>>p[i];
    sort(p+1,p+1+n);
    l=1,r=n;
    while(l<=r){
        if(p[l]+p[r]<=w) l++,r--,cnt++;
        else r--,cnt++;
    }
    cout<<cnt;
    return 0;
}