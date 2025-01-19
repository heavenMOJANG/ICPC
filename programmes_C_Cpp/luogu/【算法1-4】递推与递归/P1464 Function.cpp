#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll a,b,c,dp[30][30][30];
ll w(ll x, ll y, ll z){
    if(x<=0||y<=0||z<=0) return 1;
    if(x>20||y>20||z>20) return w(20,20,20);
    if(dp[x][y][z]) return dp[x][y][z];
    return dp[x][y][z]=w(x-1,y,z)+w(x-1,y-1,z)+w(x-1,y,z-1)-w(x-1,y-1,z-1);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>a>>b>>c){
        if(a==-1&&b==-1&&c==-1) break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<"\n";
    }
    return 0;
}