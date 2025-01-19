#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    int up=n,down=0,left=m,right=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            char ch;cin>>ch;
            if(ch=='#'){
                up=min(up,i);
                down=max(down,i);
                left=min(left,j);
                right=min(right,j);
            }
            cout<<ch;
        }
        cout<<"\n";
    }
    cout<<(up+down)/2<<" "<<(left+right)/2<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}