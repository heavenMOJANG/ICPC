#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    vector<vector<int>>a(26);
    vector<int>f(s.size(),1);
    for(int i=0;i<s.size();++i) a[s[i]-'a'].push_back(i);
    int it=0,flag=1;
    while(flag){
        if(k>=a[it].size()){
            k-=a[it].size();
            for(int i=0;i<a[it].size();++i) f[a[it][i]]=0;
            it++;
            continue;
        }
        else{
            for(int i=0;i<k;++i) f[a[it][i]]=0;
            flag=0;
        }
    }
    for(int i=0;i<s.size();++i) if(f[i]) cout<<s[i];
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
