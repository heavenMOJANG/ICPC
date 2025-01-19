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
    int num0=0;
    for(auto x:s) num0+=x=='0';
    int num1=n-num0;
    reverse(s.begin(),s.end());
    int cur=0,res=0;
    int p=0;
    while(p<n){
        if(s[p]=='0'){
            res+=p-cur;
            cur++;
            cout<<res<<" ";
        }
        p++;
    }
    for(int i=cur;i<n;++i) cout<<"-1 ";
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
