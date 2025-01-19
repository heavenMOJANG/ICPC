#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int check0(int x,int y,int z){return x==y&&y==z;}
int check1(int x,int y,int z){return z%2==0&&z/2==x&&x==y;}
int check2(int x,int y,int z){return y==z&&z%2==0&&z/2==x||x==y&&z%3==0&&z/3==x;}
int check3(int x,int y,int z){return x==y&&z%4==0&&z/4==x||z%3==0&&z/3==x&&y%2==0&&y/2==x;}
void solve(){
    int x,y,z;
    cin>>x>>y>>z;
    if(x>y) swap(x,y);
    if(x>z) swap(x,z);
    if(y>z) swap(y,z);
    if(check0(x,y,z)||check1(x,y,z)||check2(x,y,z)||check3(x,y,z)) cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
