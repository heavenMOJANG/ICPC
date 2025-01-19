#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        ll n,m,x1,y1,x2,y2;
        cin>>n>>m>>x1>>y1>>x2>>y2;
        ll dis1=4,dis2=4;
        if(x1==1||x1==n||y1==1||y1==m) dis1=3;
        if(x2==1||x2==n||y2==1||y2==m) dis2=3;
        if((x1==1||x1==n)&&(y1==1||y1==m)) dis1=2;
        if((x2==1||x2==n)&&(y2==1||y2==m)) dis2=2;
        cout<<min(dis1,dis2)<<"\n";
    }
    return 0;
}