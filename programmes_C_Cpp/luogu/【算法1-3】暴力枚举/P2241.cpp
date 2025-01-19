#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,sum1,sum2;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j) i==j?sum1+=(n-i+1)*(m-j+1):sum2+=(n-i+1)*(m-j+1);
    cout<<sum1<<" "<<sum2;
    return 0;
}