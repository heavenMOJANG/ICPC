#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    string s;cin>>s;
    int p=s.find("://");
    cout<<s.substr(0,p)<<"\n";
    s=s.substr(p+3);
    p=s.find("/");
    cout<<s.substr(0,p)<<"\n";
    s=s.substr(p+1);
    string t="";
    for(int i=0;i<s.size();++i)
        if(s[i]=='/'){
            int cnt=0;
            for(int j=0;j<t.size();++j) if(t[j]=='=') cnt++;
            if(cnt==1){
                cout<<t<<"\n";
                t="";
            }
        }
        else t+=s[i];
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}