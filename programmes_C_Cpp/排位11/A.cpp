#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=100000007;
void solve(){
    int n;
    while(cin>>n,n){
        int flag=0;
        for(int i=1;6*i*i<n;++i){
            int d=n-6*i*i;
            if(d%(7*i)==0){
                int a=d/(7*i)%mod,s=a*a*2%mod;
                cout<<"Possible Missing Soldiers = "<<s<<"\n";
                flag=1;
            }
        }
        if(!flag) cout<<"No Solution Possible\n";
        cout<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
