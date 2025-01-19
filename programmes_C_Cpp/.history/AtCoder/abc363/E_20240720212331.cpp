#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct Node{
    int h;
    bool operator>(const Node&x)const{return h<x.h};
};
int n,m,k,x,sum;
map<int,int>mp;
priority_queue<Node>pq;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) cin>>x,mp[x]++,sum+=x;
    auto it=mp.begin();
    for(int i=1;i<=k;++i){
        if(it->first<i){
            sum-=(it->first)*()
            it++;
        }
    }
    return 0;
}