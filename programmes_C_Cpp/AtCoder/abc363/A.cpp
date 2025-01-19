#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int r;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>r;
    if(1<=r&&r<=99) cout<<100-r;
    if(100<=r&&r<=199) cout<<200-r;
    if(200<=r&&r<=299) cout<<300-r;
    return 0;
}