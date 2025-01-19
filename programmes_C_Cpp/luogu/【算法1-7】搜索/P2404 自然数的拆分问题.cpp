#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,a[100]={1};
void dfs(ll x,ll sum){
	if(sum==n){
		for(ll i=1;i<x;++i){
			cout<<a[i];
			if(i!=x-1) cout<<"+"; 
		}
		cout<<"\n";
	}
	else
		for(ll i=a[x-1];i<n;++i)
			if(sum+i>n) break;
			else{
				a[x]=i;
				dfs(x+1,sum+i);
				a[x]=0; 
			}
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    dfs(1,0);
    return 0;
}