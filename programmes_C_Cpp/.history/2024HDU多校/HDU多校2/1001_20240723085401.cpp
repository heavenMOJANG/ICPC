#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    if(n==1){cout<<"1 2\n";return;}
    if(n==2){cout<<"1 2\n1 3\n";return;}
    if(n==3){cout<<"1 2\n1 3\n1 4\n";return;}
    if(n==4){cout<<"1 2\n1 3\n1 4\n1 5\n";return;}
    if(n==5){cout<<"1 2\n1 3\n1 4\n1 5\n1 6\n";return;}
    if(n==6){cout<<"1 2\n1 3\n1 4\n1 5\n2 3\n2 4\n";return;}
    for(int i = 1; i <= n / 3 + n % 3 + 2; ++ i) cout << "1 "<< i + 1<<"\n";
    for(int i = 1; i <= n / 3; ++ i) cout << "2 " << i + 2 << "\n";
    for(int i = 1; i <= n / 3 - 2; ++ i) cout << "3 " << i + 3 << "\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}