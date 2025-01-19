#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,k,a[2000010],q[2000010],head=1,tail=0;
void solve(){
    cin>>n>>k;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
        while(q[head]<=i-k&&head<=tail) head++;
        while(head<=tail&&a[q[tail]]<=a[i]) tail--;
		q[++tail]=i;
		if(i>=k) cout<<a[q[head]]<<"\n";
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}