#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
struct Node{double x,y;}a[10010];
ll n;
double minn=LLONG_MAX;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].x>>a[i].y;
    for(ll i=1;i<n;++i){
        for(ll j=i+1;j<=n;++j){
            double d=sqrt(pow(a[i].x-a[j].x,2)+pow(a[i].y-a[j].y,2));
            minn=min(minn,d);
        }
    }
    cout<<fixed<<setprecision(4)<<minn;
    return 0;
}
