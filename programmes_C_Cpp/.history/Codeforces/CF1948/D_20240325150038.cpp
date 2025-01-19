#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    string s;cin>>s;
    int n=s.size();
    vector<vector<int>>lcp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;--i)
        for(int j=n-1;j>=i;--j)
            if(s[i]==s[j]) lcp[i][j]=lcp[i+1][j+1]+1;
            else if(s[i]=='?'||s[j]=='?') lcp[i][j]=lcp[i+1][j+1]+1;
            else lcp[i][j]=0;
    int maxn=0;
    for(int i=0;i<n;++i)
        for(int j=1;i+j<n;++j)
            if(lcp[i][i+j]>=j) maxn=max(maxn,j);
    cout<<maxn<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
