#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct Shash{  
    const int base[2]={29,31};
    const int hashmod[2]={(int)1e9+9,998244353};
    array<vector<int>,2>hsh;
    array<vector<int>,2>pwMod;
    void init(string S){
        int n=S.size();S=' '+S;
        hsh[0].resize(n+1),hsh[1].resize(n+1);
        pwMod[0].resize(n+1),pwMod[1].resize(n+1);
        for(int i=0;i<2;++i){
            pwMod[i][0]=1;
            for(int j=1;j<=n;++j){
                pwMod[i][j]=pwMod[i][j-1]*base[i]%hashmod[i];
                hsh[i][j]=(hsh[i][j-1]*base[i]+S[j])%hashmod[i];
            }
        }
    }
    pair<int,int>get(int l,int r){
        pair<int,int>ans;
        ans.first=(hsh[0][r]-hsh[0][l-1]*pwMod[0][r-l+1])%hashmod[0];
        ans.second=(hsh[1][r]-hsh[1][l-1]*pwMod[1][r-l+1])%hashmod[1];
        ans.first=(ans.first+hashmod[0])%hashmod[0];
        ans.second=(ans.second+hashmod[1])%hashmod[1];
        return ans;
    }
};
bool same(Shash &a,int la,int ra,Shash &b,int lb,int rb){
    return a.get(la,ra)==b.get(lb,rb);
}
void solve(){
    string s;cin>>s;
    int n=s.size();
    string is=s;
    reverse(is.begin(),is.end());
    Shash a,b;
    a.init(s),b.init(is);
    if(!same(a,1,n,b,1,n)){
        cout<<"YES\n";
        cout<<1<<'\n';
        cout<<s<<'\n';
        return;
    }
    for(int i=2;i<=n-1;i++){
        if(!same(a,1,i,b,n-i+1,n)&&!same(a,i+1,n,b,1,n-i)){
            cout<<"YES\n";
            cout<<2<<'\n';
            cout<<s.substr(0,i)<<' '<<s.substr(i,n-i)<<'\n';
            return;
        }
    }
    cout<<"NO\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
