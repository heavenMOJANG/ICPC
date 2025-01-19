#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll n,a[100010],cur,minn=LLONG_MAX;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);
    map<ll,priority_queue<ll,vector<ll>,greater<ll>>>mp;
    for(ll i=0;i<n;++i) {
        cur=0;
        auto it=mp.find(a[i]-1);
        if(it!=mp.end())
            if(it->second.size()){
                cur=it->second.top();
                it->second.pop();
            }
        cur++;
        mp[a[i]].push(cur);
    }
    for(auto it=mp.begin();it!=mp.end();++it)
        if(!it->second.empty()) minn=min(minn,it->second.top());
    cout<<minn;
    return 0;
}