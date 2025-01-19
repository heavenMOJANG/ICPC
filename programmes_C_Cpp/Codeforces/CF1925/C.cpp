#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k,m;cin>>n>>k>>m;
    string s,t;cin>>s;
    map<char,int>mp;
    int cnt=0,i=0;
    while(i<m&&cnt<n){
        mp.clear();
        int j=i,sum=0;
        while(j<m&&sum<k){
            int c=s[j]-'a';
            if(c<k&&mp[c]==0) sum++;
            mp[c]++;
            j++;
        }
        if(sum<k) break;
        t+=s[j-1];
        cnt++;
        i=j;
    }
    if(cnt==n){cout<<"YES\n";return;}
    cout<<"NO\n";
    for(int i=0;i<k;++i){
        if(mp[i]==0){
            cout<<t<<string(n-t.size(),char('a'+i))<<'\n';
            return;
        }
    }
    cout<<t<<string(n-t.size(),'a')<<'\n';
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
