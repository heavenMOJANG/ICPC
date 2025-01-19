#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1,0),treeMax(n+1<<2,LLONG_MAX),treeMin(n+1<<2,LLONG_MIN);
    set<int>s;
    function<void(int)> pushUp=[&](int p){
        treeMax[p]=max(treeMax[p<<1],treeMax[p<<1|1]);
        treeMin[p]=min(treeMin[p<<1],treeMin[p<<1|1]);
        return;
    };
    function<void(int,int,int,int,int)> modify=[&](int p,int pl,int pr,int x,int d){
        if(pl==pr){treeMax[p]=treeMin[p]=d;return;}
        int mid=pl+pr>>1;
        if(mid>=x) modify(p<<1,pl,mid,x,d);
        if(mid<x) modify(p<<1|1,mid+1,pr,x,d);
        pushUp(p);
        return;
    };
    function<pair<int,int>(int,int,int,int,int)> query=[&](int p,int pl,int pr,int L,int R){
        if(L<=pl&&pr<=R) return make_pair(treeMax[p],treeMin[p]);
        int mid=pl+pr>>1,maxn=LLONG_MIN,minn=LLONG_MAX;
        if(mid>=L){
            pair<int,int> res=query(p<<1,pl,mid,L,R);
            maxn=max(maxn,res.first),minn=min(minn,res.second);
        }
        if(mid<R){
            pair<int,int> res=query(p<<1|1,mid+1,pr,L,R);
            maxn=max(maxn,res.first),minn=min(minn,res.second);
        }
        return make_pair(maxn,minn);
    };
    for(int i=1;i<=n;++i){
        cin>>a[i];
        modify(1,1,n,i,a[i]);
        if(i>1&&a[i]<a[i]-a[i-1]) s.insert(i);
    }
    if(!s.size()) cout<<"-1 -1\n";
	else{
		int l=*s.begin(), r=*s.rbegin();
		pair<int,int> tmp=query(1,1,n,l-1,r);
		int L=upper_bound(a.begin()+1,a.begin()+l,tmp.second)-a.begin(),R=lower_bound(a.begin()+r+1,a.begin()+1+n,tmp.first)-a.begin()-1;
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
        int L=upper_bound(a.begin()+1,a.begin()+l,tmp.second)-a.begin(),R=lower_bound(a.begin()+r+1,a.begin()+1+n,tmp.first)-a.begin()-1;
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