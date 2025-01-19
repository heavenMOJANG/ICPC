#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,r,a[30],rec[30],cnt;
void dfs(ll x,ll num){
    if(num==r){for(ll i=0;i<r;++i) cout<<setw(3)<<rec[i];cout<<"\n";return;}
    for(ll i=x;i<n;++i){
        rec[cnt]=a[i],cnt++;
        dfs(i+1,num+1);
        cnt--;
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>r;
    for(ll i=0;i<n;++i) a[i]=i+1;
    dfs(0,0);
    return 0;
}