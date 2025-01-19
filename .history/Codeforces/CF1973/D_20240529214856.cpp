#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int ask(int l,int w){
    cout<<"? "<<l<<" "<<w<<endl;
    int res;cin>>res;
    return res;
}
void solve(){
    int n,k;cin>>n>>k;
    int maxn;
    for(int i=1;i<=n;++i)
        if(ask(1,n*i)==n){maxn=i;break;}
    for(int i=n/k;i;--i){
        int head=1,cnt=1;
		int flag=1;
		while(cnt<=k&&head<=n){
			int r=ask(head,maxn*i);
			if(r==n+1){flag=0;break;}
			head=r+1;
			cnt+=1;
		}
		if(flag&&cnt==k+1&&head==n+1){
			cout<<"! "<<i*maxn<<endl;
			cin>>n;
			return;
		}
    }
    cout<<"! -1"<<endl;
    cin>>n;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}