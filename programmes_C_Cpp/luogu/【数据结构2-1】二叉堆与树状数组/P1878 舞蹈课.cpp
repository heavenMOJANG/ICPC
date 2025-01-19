#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
struct Node{
	ll l,r,val;
	bool operator<(const Node&x) const{return x.val==val?x.l<l:x.val<val;}
};
ll len,n,que[200010],a[200010],ans,group1[200010],group2[200010],rlen,vis[200010];
priority_queue<Node>heap;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
	for(ll i=1;i<=n;++i){
		char c;cin>>c;
		if(c=='B') que[i]=1; 
	}
	cin>>a[1];
	for(ll i=2;i<=n;++i){
        cin>>a[i];
		if(que[i]!=que[i-1]){
			Node rec;
			rec.l=i-1;
            rec.r=i;
			rec.val=abs(a[i]-a[i-1]);
			heap.push(rec);
		}
	}
	while(!heap.empty()){
		Node rec=heap.top();
		ans++;
		group1[ans]=rec.l;
		group2[ans]=rec.r;
		vis[rec.l]=vis[rec.r]=1; 
		while(vis[rec.l]||vis[rec.r]){
			if(heap.empty()) break;
			heap.pop();
			rec=heap.top();
		}
		ll l=group1[ans];
        ll r=group2[ans]; 
		while(l>0&&vis[l]) l--;
		while(r<=n&&vis[r]) r++;
		if(que[l]!=que[r]&&l>0&&r<=n){
			rec.l=l;
			rec.r=r;
			rec.val=abs(a[l]-a[r]);
			heap.push(rec);
		}
	}
	cout<<ans<<"\n";
	for(ll i=1;i<=ans;++i) cout<<group1[i]<<" "<<group2[i]<<"\n";
    return 0;
}