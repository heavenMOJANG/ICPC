#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,m,q;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>q;
    function<int(int,int)> qpow=[&](int a,int x){
        int res=1;
        while(x){
            if(x&1) res=res*a%q;
            a=a*a%q;
            x>>=1;
        }
        return res;
    };
    
    return 0;
}