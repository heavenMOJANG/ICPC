#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s[30],ans;
int cmp(string x,string y){return (x+y)>(y+x);}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>s[i];
    sort(s+1,s+1+n,cmp);
    for(ll i=1;i<=n;++i) ans+=s[i];
    cout<<ans;
    return 0;
}