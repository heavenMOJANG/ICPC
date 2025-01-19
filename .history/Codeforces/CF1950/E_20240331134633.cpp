#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int ans=n;
    function<int(int)> check=[&](int len){
        string s1,s2;
        for(int i=0; i<len;++i) s1+=s[i];
        if(len<s.size()) for(int i=len;i<2*len;++i)s2+=s[i];
        int sum1=0,sum2=0;
        for(int i=0;i<s.size();++i){
            int now=i%len ;
            if(s1[now]!=s[i]){sum1++;if(sum1>1) break;}
        }
        if(sum1<=1) return 1;
        for(int i=0;i<s.size();++i){
            int now=i%len;
            if(s2[now]!=s[i]){sum2++;if(sum2>1) break;}
        }
        if(sum2<=1) return 1;
        return 0;
    };
    for(int i=1;i<=sqrt(n);++i)
        if(n%i==0){
            int x=i,y=n/i;
            if(check(x)){cout<<x<<"\n";return;}
            if(y!=x){if(check(y)) ans=y;}
        }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
