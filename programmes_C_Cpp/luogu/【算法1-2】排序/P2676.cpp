#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,h[20010],b,cnt,sum;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>b;
    for(ll i=1;i<=n;++i) cin>>h[i];
    sort(h+1,h+1+n,greater<ll>());
    for(ll i=1;i<=n;++i){
        sum+=h[i],cnt++;
        if(sum>=b){cout<<cnt;break;}
    }
    return 0;
}