#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,a[100010]={1};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=0;i<1<<n;++i){
        for(ll j=1;j<(1<<n)-i;++j) cout<<" ";
        for(ll j=i;j>=0;--j) a[j]^=a[j-1];
        if(i&1) for(ll j=0;j<=i;j+=2) cout<<(a[j]?"/__\\":"    ");
        else for(ll j=0;j<=i;++j) cout<<(a[j]?"/\\":"  ");
        cout<<"\n";
    }
    return 0;
}