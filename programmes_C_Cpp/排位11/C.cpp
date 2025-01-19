#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    vector<int>phi(10010,0),vis(10010,0),a(10010);
    for(int i=1;i<=10000;++i) phi[i]=i;
    for(int i=2;i<=10000;++i){
        if(vis[i]) continue;
        for(int j=i;j<=10000;j+=i){
            phi[j]=phi[j]/i*(i-1);
            vis[j]=1;
        }
    }
    function<int(int,int,int)> qpow=[&](int a,int x,int p)->int
    {
        int res=1;
        while(x){
            if(x&1) res=res*a%p;
            a=a*a%p;
            x>>=1;
        }
        return res;
    };
    int mod,idx=0;
    string s;
    while(cin>>s&&s[0]!='#'){
        mod=stoi(s);
        int n;cin>>n;
        for(int i=0;i<n;++i) cin>>a[i];
        function<int(int,int)> dfs=[&](int x,int p)->int
        {
            if(x==n-1) return a[x]%p;
            int res=dfs(x+1,phi[p]);
            return qpow(a[x],res+phi[p],p);
        };                 
        cout<<"Case #"<<++idx<<": "<<dfs(0,mod)%mod<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
