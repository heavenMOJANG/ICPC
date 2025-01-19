#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    function<int(int,int,int)> qpow=[&](int a,int x,int p)->int
    {
        int res=1;
        while(x){
            if(x&1) res=res&a%p;
            a=a*a%p;
            x>>=1;
        }
        return res;
    };
    int mod,idx=0;
    while(cin>>mod,mod){
        vector<int>a,b;
        int k;
        cin>>k; for(int i=0,x;i<=k;++i) cin>>x,a.push_back(x);
        cin>>k; for(int i=0,x;i<=k;++i) cin>>x,b.push_back(x);
        function<vector<int>(vector<int>,vector<int>)> polyGcd=[&](vector<int>f,vector<int>g)->vector<int>
        {
            if(!g.size()) return f;
            int t=f.size()-g.size();
            vector<int>d;
            for(int i=0;i<t;++i){
                int tmp=f[i]*qpow(g[0],mod-2,mod)%mod;
                for(int j=0;j<g.size();++j) f[i+j]=(f[i+j]-tmp*g[j]%mod+mod)%mod;
            }
            int p=-1;
            for(int i=0;i<f.size();++i) if(f[i]!=0){p=i;break;}
            if(p>=0) for(int i=p;i<f.size();++i) d.push_back(f[i]);
            return polyGcd(g,d);
        };
        vector<int> ans=polyGcd(a,b);
        int res=qpow(ans[0],mod-2,mod);
        cout<<"Case "<<++idx<<": "<<ans.size()-1<<" ";
        for(int i=0;i<ans.size();++i) cout<<(ans[i]=ans[i]*res%mod)<<" \n"[i==ans.size()-1];
        }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
