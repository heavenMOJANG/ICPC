#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,m;
void solve(){
    cin>>n>>m;
    ll x=0,y=0,cnt=0;
    vector<string>v(200010,"");
    do{
        v[cnt]=to_string(x)+" "+to_string(y)+" ";
        if(n<m) v[cnt]+=to_string(n)+"\n",y+=n,m-=n;
        else v[cnt]+=to_string(m)+"\n",x+=m,n-=m;
        cnt++;
    }while(n&&m);
    cout<<"YES\n"<<cnt<<"\n";
    for(string s:v) cout<<s;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
