#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Node{
    ll pos,type;
    bool operator<(const Node&x)const{return pos<x.pos;}
}a[50010];
ll n,m,minn=LLONG_MAX;
map<ll,ll>mp;
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].pos>>a[i].type,mp[a[i].type]++;
    sort(a+1,a+1+n);
    m=mp.size();mp.clear();
    ll l=1,r=1;
    mp[a[1].type]++;
    while(r<=n){
        if(mp.size()==m){
            minn=min(minn,a[r].pos-a[l].pos);
            mp[a[l].type]--;
            if(mp[a[l].type]==0) mp.erase(a[l].type);
            l++;
        }
        else r++,mp[a[r].type]++;
    }
    cout<<minn;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}