#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(int n){
    vector<int>s(n),t(n);
    for(int i=0;i<n;++i) cin>>s[i];
    for(int i=0;i<n;++i) cin>>t[i];
    int m=n-1;
    while(m>=0&&s[m]==t[m]) m--;
    int cur=6-s[m]-t[m];
    function<int(int,vector<int>)> dfs=[&](int x,vector<int> a)->int{
        if(x==-1) return 0;
	    if(a[x]==cur) return dfs(x-1,a);
	    return dfs(x-1,a)+(1ll<<x);
    };
    if(m>=0) cout<<dfs(m-1,s)+dfs(m-1,t)+1<<"\n";
    else cout<<"0\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1,idx=0;
    while(cin>>_&&_){
        cout<<"Case "<<++idx<<": ";
        solve(_);
    }
    return 0;
}
