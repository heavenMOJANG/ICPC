#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int T;
int n;
int a[210];
int cnt[210],tag,tot;
void solve(){
    memset(cnt,0,sizeof(cnt));
    tag=tot=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cnt[a[i]]++;
        if(cnt[a[i]]==2) tot++;
    }
    if(tot<2){cout<<"-1\n";return;}
    for(int i=1;i<=100;++i) if(cnt[i]>=2){tag=i;break;}
    for(int i=1;i<=n;++i){
        if(tag==a[i]){
            if(cnt[a[i]]==1) cout<<"3 ";
            else cout<<"2 ";
        }
        else{
            if(cnt[a[i]]==1) cout<<"2 ";
            else cout<<"1 ";
        }
        cnt[a[i]]--;
    }
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
