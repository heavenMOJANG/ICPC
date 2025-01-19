#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    if(n==2){cout<<"! 0 1"<<endl;return;}
    int maxn=0;
    for(int i=1;i<n;++i){
        cout<<"? "<<i<<" "<<i<<" "<<maxn<<" "<<maxn<<endl;
        char ch;cin>>ch;
        if(ch=='>') maxn=i;
    }
    int ans=(maxn==0);
    vector<int>a;
    for(int i=0;i<n;++i){
        if(i==maxn) continue;
        cout<<"? "<<maxn<<" "<<ans<<" "<<maxn<<" "<<i<<endl;
        char ch;cin>>ch;
        if(ch=='=') a.push_back(i);
        if(ch=='<') a.clear(),ans=i,a.push_back(i);
    }
    for(auto x:a){
        cout<<"? "<<ans<<" "<<ans<<" "<<x<<" "<<x<<endl;
        char ch;cin>>ch;
        if(ch=='>') ans=x;
    }
    cout<<"! "<<maxn<<" "<<ans<<endl;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
