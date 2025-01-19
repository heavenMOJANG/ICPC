#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,ans,f[6][60];
string s[200010];
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>s[i];
    sort(s+1,s+1+n,[](string a,string b){return a.size()<b.size();});
    for(int i=1;i<=n;++i){
        int sum=0;
        int m=s[i].size();
        for(auto c:s[i]) sum+=(c-'0');
        int res=0;
        for(int j=0,l=1;j<s[i].size();j++,l++) {
            res+=(s[i][j]-'0');
            for(int len=1;len<=5;++len) if((l+len)==(m-l)) ans+=f[len][sum-res*2];
        }
        ans+=f[m][sum]*2;
        res=0;
        for(int j=m-1,l=1;j>=0;--j,++l){
            res+=(s[i][j]-'0');
            for(int len=1;len<=5;++len) if((l+len)==(m-l)) ans+=f[len][sum-res*2];
        }
        ans++;
        f[m][sum]++;
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
