#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
string s;
void solve(){
    cin>>s;
    for(char ch:s){
        if(ch=='3'){
            cout<<"37\n";
            break;
        }
        if(ch=='7'){
            cout<<"73\n";
            break;
        }
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
