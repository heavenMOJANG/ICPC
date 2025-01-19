#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>ans,clr;
    int t=min(n,k),cnt=0;
    for(int i=1;i<=n;i+=t){
            int l=i,r=min(n,i+t-1);
            cnt++;
            vector<int>v;
            for(int j=l;j<=r;++j){
                ans.push_back(cnt);
                v.push_back(j);
            }
            rotate(v.begin(),v.begin()+v.size()/2,v.end());
            clr.insert(clr.end(),v.begin(),v.end());
        }
        for(int i=0;i<clr.size();++i) cout<<clr[i]<<" \n"[i==clr.size()-1];
        cout<<cnt<<"\n";
        for(int i=0;i<ans.size();++i) cout<<ans[i]<<" \n"[i==ans.size()-1];
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
