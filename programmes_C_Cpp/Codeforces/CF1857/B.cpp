#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n;
string s;
void solve(){
    cin>>s;
    n=s.size();
    ll last=n;
    for(ll i=n-1;i>=0;--i){
        if(s[i]>='5'){
            ll j=i-1;
            while(j>=0&&s[j]=='9') j--;
            if(j<0){
                s="1"+string(n,'0');
                break;
            }
            while(last-1>j) s[--last]='0';
            s[j]+=1;
            i=j+1;
        }
    }
    cout<<s<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}