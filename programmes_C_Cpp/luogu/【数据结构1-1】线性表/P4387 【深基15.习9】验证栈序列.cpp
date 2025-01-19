#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll q,n,a[100010],b[100010];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>q;
    while(q--){
        cin>>n;
        if(!n){cout<<"No\n";continue;}
        for(ll i=1;i<=n;++i) cin>>a[i];
        for(ll i=1;i<=n;++i) cin>>b[i];
        stack<ll>s;
        ll idx=1;
        for(ll i=1;i<=n;++i){
            s.push(a[i]);
            while(!s.empty()&&s.top()==b[idx]){
                s.pop();
                idx++;
            }
        }

        cout<<(s.size()==0?"Yes\n":"No\n");
    }
    return 0;
}