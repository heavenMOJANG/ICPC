#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    auto [p1,p2]=minmax_element(a.begin(),a.end());
    int minn=*p1,maxn=*p2;
    vector<int>ans;
    while(minn!=maxn){
        if(minn%2==1){
            ans.push_back(1);
            minn=(minn+1)/2;
            maxn=(maxn+1)/2;
        }
        else{
            ans.push_back(0);
            minn/=2;
            maxn/=2;
        }
    }
    cout<<ans.size()<<"\n";
    if(ans.size()<=n){
        for(auto x:ans) cout<<x<<" ";
        cout<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
