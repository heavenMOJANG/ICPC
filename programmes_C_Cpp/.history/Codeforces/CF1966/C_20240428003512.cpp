#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    int flag=1;
    set<int>s;
    for(int i=0;i<n;++i){
        cin>>a[i];
        s.insert(a[i]);
        if(a[i]!=a[0]) flag=0;
    }
    if(n==1||flag){cout<<"Alice\n";return;}
    int len=1;
    int pre=*s.begin();s.erase(pre);
    int is1=(pre==1);
    vector<int>v;
    for(auto it=s.begin();it!=s.end();++it){
        if(*it==pre+1) len++;
        else{
            v.emplace_back(len);
            len=1;
        }
        pre=*it;
    }
    v.emplace_back(len);
    if(is1){
        if(v.size()==1) cout<<(v[0]&1?"Alice\n":"Bob\n");
        else cout<<(v[0]&1?"Bob\n":"Alice\n");
    }
    else cout<<"Alice\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}