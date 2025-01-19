#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,x,y,k;
void dfs(ll a,ll b,ll x,ll y,ll n){
    if(n==1) return;
    n/=2;
    if(x<=a+n-1&&y<=b+n-1){
        cout<<a+n<<" "<<b+n<<" 1\n";
        dfs(a,b,x,y,n);
        dfs(a,b+n,a+n-1,b+n,n);
        dfs(a+n,b,a+n,b+n-1,n);
        dfs(a+n,b+n,a+n,b+n,n);
    }
    else if(x<=a+n-1&&y>=b+n){
        cout<<a+n<<" "<<b+n-1<<" 2\n";
        dfs(a,b,a+n-1,b+n-1,n);
        dfs(a,b+n,x,y,n);
        dfs(a+n,b,a+n,b+n-1,n);
        dfs(a+n,b+n,a+n,b+n,n);
    }
    else if(x>=a+n&&y<=b+n-1){
        cout<<a+n-1<<" "<<b+n<<" 3\n";
        dfs(a,b,a+n-1,b+n-1,n);
        dfs(a,b+n,a+n-1,b+n,n);
        dfs(a+n,b,x,y,n);
        dfs(a+n,b+n,a+n,b+n,n);
    }
    else{
        cout<<a+n-1<<" "<<b+n-1<<" 4\n";
        dfs(a,b,a+n-1,b+n-1,n);
        dfs(a,b+n,a+n-1,b+n,n);
        dfs(a+n,b,a+n,b+n-1,n);
        dfs(a+n,b+n,x,y,n);
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>k>>x>>y;n=1<<k;
    dfs(1,1,x,y,n);
    return 0;
}