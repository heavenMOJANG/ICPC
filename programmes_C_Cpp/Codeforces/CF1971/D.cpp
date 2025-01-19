#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    string s;cin>>s;
    int res=0,flag=0;
    for(int i=s.size()-1;i>=0;)
        if(s[i]=='0'){
            res++;
            while(s[i]=='0') i--;
        }
        else{
            while(s[i]=='1') i--;
            if(!flag&&i>=0&&s[i]=='0'){
                flag=1;
                while(s[i]=='0') i--;
            }
            res++;
        }
    cout<<res<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}