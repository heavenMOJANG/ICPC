#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[15];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) a[i]=i;
    do{
        for(ll i=1;i<=n;++i) cout<<setw(5)<<a[i];
        cout<<"\n";
    }while(next_permutation(a+1,a+1+n));
    return 0;
}