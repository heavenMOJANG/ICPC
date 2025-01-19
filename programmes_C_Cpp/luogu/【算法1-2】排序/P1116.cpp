#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[10010],cnt;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    for(ll i=1;i<n;++i)
        for(ll j=i+1;j<=n;++j)
            if(a[i]>a[j]) swap(a[i],a[j]),cnt++;
    cout<<cnt;
    return 0;
}