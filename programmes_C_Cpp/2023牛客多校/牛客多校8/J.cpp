#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,b,k,idx;
void solve(){
    cin>>n;
    b=n%8;
    k=n/8;
    switch(b){
        case 1:cout<<"1 ";break;
        case 2:cout<<"1 2 ";break;
        case 3:cout<<"1 2 3 ";break;
        case 4:cout<<"1 4 3 2 ";break;
        case 5:cout<<"1 4 3 2 5 ";break;
        case 6:cout<<"1 4 3 2 5 6 ";break;
        case 7:cout<<"1 4 7 2 3 6 5 ";break;
    }
    idx=b;
    for(ll i=1;i<=k;++i,idx+=8)
        cout<<idx+1<<" "<<idx+6<<" "<<idx+3<<" "<<idx+8<<" "<<idx+5<<" "<<idx+2<<" "<<idx+7<<" "<<idx+4<<" ";
    cout<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}