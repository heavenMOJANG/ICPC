#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[1010],sum;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
        if(i!=1) sum+=abs(a[i]-a[i-1]);
    }
    cout<<(sum==(n-1)*n/2?"Jolly":"Not jolly");
    return 0;
}