#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int l=0,r=s.size()-1,flag=0;
    while(l<=r)
        if(s[l]==s[r]) l++,r--;
        else break;
    if(l<=r&&s[l]<s[r]) flag=0;
    else flag=1;
    if(flag){
        reverse(s.begin(),s.end());cout<<s;
        reverse(s.begin(),s.end());cout<<s<<"\n";
    }
    else cout<<s<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
