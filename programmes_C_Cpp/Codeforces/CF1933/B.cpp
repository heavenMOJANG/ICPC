#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    map<int,int>mp;
    int sum=0;
    for(int i=0,x;i<n;++i) cin>>x,sum+=x,mp[x%3]++;
    if(sum%3==0){cout<<"0\n";return;}
    if(sum%3==1){
        if(mp[1]){cout<<"1\n";return;}
        else{cout<<"2\n";return;}
    }
    else{cout<<"1\n";return;}
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
