#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m,x,y;cin>>n>>m;
    vector<pii>vp;
    vector<int>b;
    for(int i=0;i<n;++i){
        cin>>x>>y;
        vp.push_back({x,y});
        b.push_back(x);
        b.push_back(y);
        b.push_back(max(1ll,x-1));
        b.push_back(max(1ll,y-1));
        b.push_back(min(m,x+1));
        b.push_back(min(m,y+1));
    }
    sort(b.begin(),b.end());
    auto it=unique(b.begin(),b.end());
    b.erase(it,b.end());
    m=b.size();
    map<int,int>mp;
    for(int i=0;i<m;++i) mp[b[i]]=i+1;
    for(auto &p:vp) p.first=mp[p.first],p.second=mp[p.second];
    sort(vp.begin(),vp.end());
    int res=0;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    x=0,y=0;
    for(int i=1,j=0;i<=m;++i){
        while(j<n&&vp[j].first<=i){
            pq.push({vp[j].second,vp[j].first});
            if(vp[j].first==1) x++;
            if(vp[j].second==m) y++;
            j++;
        }
        while(!pq.empty()&&pq.top().first<i){
            auto p=pq.top();
            pq.pop();
            if(p.second==1) x--;
            if(p.first==m) y--;
        }
        res=max(res,(int)pq.size()-min(x,y));
    }
    cout<<res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
