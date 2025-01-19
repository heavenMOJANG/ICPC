#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,tmp,A[100010],B[100010],idx[100010];
priority_queue<pll,vector<pll>,greater<pll>>q;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=0;i<n;++i) cin>>A[i];
	for(ll i=0;i<n;++i) cin>>B[i];
	sort(A,A+n);
	sort(B,B+n);
	for(ll i=0;i<n;++i) q.push({A[i]+B[0],i});
	for(ll i=0;i<n-1;++i){
		cout<<q.top().first<<" ";
		tmp=q.top().second;
		q.pop();
		q.push({A[tmp]+B[++idx[tmp]],tmp});
	}
	cout<<q.top().first<<"\n";
    return 0;
}