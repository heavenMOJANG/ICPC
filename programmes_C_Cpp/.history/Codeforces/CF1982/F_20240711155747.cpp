#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=5e5+10;
int a[N],treeMax[N<<2],treeMin[N<<2];
void pushUp(int p){
    treeMax[p]=max(treeMax[p<<1],treeMax[p<<1|1]);
    treeMin[p]=min(treeMin[p<<1],treeMin[p<<1|1]);
    return;
}
void modify(int p,int pl,int pr,int x,int d){
    if(pl==pr){treeMax[p]=treeMin[p]=d;return;}
    int mid=pl+pr>>1;
    if(mid>=x) modify(p<<1,pl,mid,x,d);
    if(mid<x) modify(p<<1|1,mid+1,pr,x,d);
    pushUp(p);
    return;
}
pii query(int p,int pl,int pr,int L,int R){
    if(L<=pl&&pr<=R) return {treeMax[p],treeMin[p]};
    int mid=pl+pr>>1,maxn=LLONG_MIN,minn=LLONG_MAX;
    if(mid>=L){
        pair<int,int> res=query(p<<1,pl,mid,L,R);
        maxn=max(maxn,res.first),minn=min(minn,res.second);
    }
    if(mid<R){
        pair<int,int> res=query(p<<1|1,mid+1,pr,L,R);
        maxn=max(maxn,res.first),minn=min(minn,res.second);
    }
    return {maxn,minn};
}
void solve(){
    int n;cin>>n;
    memset(treeMax,0x7f,sizeof(treeMax));
    memset(treeMin,-0x7f,sizeof(treeMin));
    set<int>s;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        modify(1,1,n,i,a[i]);
        if(i>1&&a[i]<a[i]-a[i-1]) s.insert(i);
    }
    if(!s.size()) cout<<"-1 -1\n";
	else{
		int l=*s.begin(),r=*s.rbegin();
		pair<int,int> tmp=query(1,1,n,l-1,r);
		int L=upper_bound(a+1,a+l,tmp.second)-a,R=lower_bound(a+r+1,a+1+n,tmp.first)-a-1;
		cout<<L<<" "<<R<<"\n";
	}
    int q;cin>>q;
    while(q--){
        int pos,x;cin>>pos>>x;
        a[pos]=x;
        modify(1,1,n,pos,x);
        if(pos>1&&a[pos]<a[pos-1]) s.insert(pos);
        if(pos>1&&a[pos]>=a[pos-1]&&s.count(pos)) s.erase(pos);
        if(pos<n&&a[pos+1]<a[pos]) s.insert(pos+1);
        if(pos<n&&a[pos+1]>=a[pos]&&s.count(pos+1)) s.erase(pos+1);
        if(!s.size()){cout<<"-1 -1\n";continue;}
        int l=*s.begin(),r=*s.rbegin();
        pair<int,int> tmp=query(1,1,n,l-1,r);
        int L=upper_bound(a+1,a+l,tmp.second)-a,R=lower_bound(a+r+1,a+1+n,tmp.first)-a-1;
		cout<<L<<" "<<R<<"\n";
    }
    return;
}
#undef int
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}