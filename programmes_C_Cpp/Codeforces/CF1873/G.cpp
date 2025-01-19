#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    string s;cin>>s;
    ll n=s.size(),sum=count(s.begin(),s.end(),'A');
    if(sum==n){cout<<"0\n";return;}
    if(s[0]=='A'&&s[n-1]=='A'){
        ll flag=1;
        for(ll i=0;i<n-1;++i) if(s[i]=='B'&&s[i+1]=='B') flag=0;
        if(flag){
            ll minn=LLONG_MAX,p=-1;
            for(ll i=0;i<n;++i){
                if(s[i]=='A') continue;
                minn=min(minn,i-p-1);
                p=i;
            }
            minn=min(minn,n-p-1);
            sum-=minn;
        } 
    }
    cout<<sum<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
