#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{double x,y,z;}a[50010];
ll n;
double sum;
int cmp(node tx,node ty){return tx.z<ty.z;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].x>>a[i].y>>a[i].z;
    sort(a+1,a+1+n,cmp);
    for(ll i=2;i<=n;++i) sum+=sqrt(pow(abs(a[i].x-a[i-1].x),2)+pow(abs(a[i].y-a[i-1].y),2)+pow(abs(a[i].z-a[i-1].z),2));
    cout<<fixed<<setprecision(3)<<sum;
    return 0;
}