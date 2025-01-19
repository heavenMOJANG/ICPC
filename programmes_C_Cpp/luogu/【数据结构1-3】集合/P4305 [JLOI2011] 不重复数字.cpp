#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll t,n;
map<ll,ll>mp;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        mp.clear();
        cin>>n;
        for(ll i=1,x;i<=n;++i){
            cin>>x;
            if(mp.find(x)==mp.end()) cout<<x<<" ";
            mp[x]++;
        }
        cout<<"\n";
    }
    return 0;
}