#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    map<int,int>mp;
    for(int i=0,x;i<n;++i) cin>>x,mp[x]++;
    priority_queue<int,vector<int>,less<int>>pq;
    for(auto it=mp.begin();it!=mp.end();++it) pq.push(it->second);
    while(pq.top()>=k){
        int t=pq.top();pq.pop();
        if(!pq.empty()){
            int p=pq.top();pq.pop();
            p+=k-1;
            pq.push(p);
        }
        else break;
    }
    int ans=0;
    while(!pq.empty()) ans+=pq.top(),pq.pop();
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}