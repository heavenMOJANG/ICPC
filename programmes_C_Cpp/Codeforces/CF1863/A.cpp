#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a,q;
string s;
void solve(){
    cin>>n>>a>>q>>s;
    ll cnt=0,ol=a,maxn=a;
    for(auto p:s){
        if(p=='+'){
            a++;
            cnt++;
            maxn=max(maxn,a);
        }
        else a--;
    }
    if(maxn==n){cout<<"YES\n";return;}
    cout<<(ol+cnt>=n?"MAYBE\n":"NO\n");
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
