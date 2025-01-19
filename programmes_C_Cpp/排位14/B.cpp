#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    string s;
    while(getline(cin,s)){
        list<char>l;
        auto it=l.begin();
        for(char ch:s){
            switch(ch){
                case '[':it=l.begin();break;
                case ']':it=l.end();break;
                default:it=l.insert(it,ch),it++;break;
            }
        }
        for(it=l.begin();it!=l.end();++it) cout<<*it;
        cout<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
