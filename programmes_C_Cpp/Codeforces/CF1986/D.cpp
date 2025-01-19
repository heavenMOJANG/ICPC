#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    vector<int>mask(n);
    for(int i=0;i<n;++i) mask[i]=s[i]-'0';
    int ans=inf;
    for(int i=1;i<n;++i){
        vector<int>v;
        int tot=0;
        for(int j=0;j<n;++j)
            if(j==i-1){
                v.emplace_back(mask[j]*10+mask[j+1]);
                j++;
            }
            else v.emplace_back(mask[j]);
        for(auto x:v){
            if(x==0){cout<<"0\n";return;}
            if(x==1) continue;
            else tot+=x;
        }
        if(!tot) tot++;
        ans=min(ans,tot);
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}