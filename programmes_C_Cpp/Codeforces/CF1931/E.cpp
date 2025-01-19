#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>v;
    int ans=0;
    string s;
    for(int i=1;i<=n;++i){
        cin>>s;
        int sz=s.size(),j=sz-1,cnt=0;
        while(s[j]=='0'&&j>=0){
            j--;
            cnt++;
        }
        if(cnt) v.push_back(cnt);
        ans+=sz-cnt;
    }
    sort(v.begin(),v.end());
    int cur=0;
    for(int i=v.size()-1;i>=0;--i){
        if(cur%2) ans+=v[i];
        cur++;
    }
    cout<<(ans>m?"Sasha\n":"Anna\n");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
