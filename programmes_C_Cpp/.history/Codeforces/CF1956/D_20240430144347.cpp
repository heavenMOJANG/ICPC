#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    vector<pii>ans;
    auto operate=[&](int l,int r){
        set<int>s(a.begin()+l,a.begin()+r+1);
        int mex=0;
        while(s.contains(mex)) mex+=1;
        for(int i=l;i<=r;++i) a[i]=mex;
        ans.push_back({l,r});
    };
    function<void(int,int)> dfs=[&](int l,int r){
        if (l==r){
            if (a[r] != 0){
                operation(l, r);
            }
            return;
        }
        int len=r-l+1,target=len-1;
        if(a[l]!=target){
            if(a[l]>target) operate(l,l);
            dfs(l+1,r);
            operate(l,r);
        }
        dfs(l+1,r);
    };
    return;
}
signed main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int _=1;//cin>>_;
    while(_--) solve();
    return 0;
}