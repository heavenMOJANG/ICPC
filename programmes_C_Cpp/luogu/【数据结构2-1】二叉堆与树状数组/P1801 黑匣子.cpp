#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
priority_queue<ll,vector<ll>,greater<ll>>box;
priority_queue<ll>w;
ll m,n,a[200010],u[200010],cur;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cur=1;
    cin>>m>>n;
    for(ll i=1;i<=m;++i) cin>>a[i];
    for(ll i=1;i<=n;++i) cin>>u[i];
    for(ll i=1;i<=m;++i){
        w.push(a[i]);
        box.push(w.top());
        w.pop();
        while(i==u[cur]){
            cout<<box.top()<<"\n";
            w.push(box.top());
            box.pop();
            cur++;
        }
    }
    return 0;
}