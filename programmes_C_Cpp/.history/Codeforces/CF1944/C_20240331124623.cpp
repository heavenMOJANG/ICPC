#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a;
    unordered_map<int, int> mp;
    for(int i=0,x;i<n;++i){
        cin>>x;
        a.push_back(x);
        mp[x]++;
    }
    sort(a.begin(),a.end());
    if(a[0] != 0){cout<<"0\n";return;}
    int idx=0;
    while(mp[idx]) idx++;
    int first=-1,second=-1;
    for(int i=0;i<idx;++i)
        if(mp[i]==1){
            if(first==-1) first=i;
            else{second=i;break;}
        }
    if(second==-1) cout<<idx<<"\n";
    else cout<<second<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
