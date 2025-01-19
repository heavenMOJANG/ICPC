#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,res;
vector<ll>v[1000010];
stack<ll>st;
void solve(){
    cin>>n;
    for(ll i=1,x;i<=n;++i){
        cin>>x;
        if(x==1){
            st.push(i);
            v[x].push_back(i);
        }
        else{
            ll tmp=0;
            if(!v[x-1].empty()){
                tmp=v[x-1].back();
                v[x].push_back(tmp),v[x-1].pop_back();
            }
            while(!st.empty()&&st.top()>tmp) st.pop();
        }
        res+=st.size();
    }
    cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}