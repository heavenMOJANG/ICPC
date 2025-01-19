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
ll t;
bool check(ll a,ll b,ll c){return 1000*a<b*b+c*c;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        ll x1,y1,z1,x2,y2,z2,flag=1;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        if(check(-x1,y1,z1)!=check(-x2,y2,z2)) flag=0;
        if(check(x1,y1,z1)!=check(x2,y2,z2)) flag=0;
        if(check(-y1,x1,z1)!=check(-y2,x2,z2)) flag=0;
        if(check(y1,x1,z1)!=check(y2,x2,z2)) flag=0;
        if(check(-z1,x1,y1)!=check(-z2,x2,y2)) flag=0;
        if(check(z1,x1,y1)!=check(z2,x2,y2)) flag=0;
        cout<<(flag?"Yes\n":"No\n");
    }
    return 0;
}