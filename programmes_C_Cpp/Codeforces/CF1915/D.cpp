#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    queue<char>q;
    for(int i=0;i<n;++i){
        if(s[i]=='a'||s[i]=='e') q.push(s[i]);
        else{
            if(q.empty()||i==n-1||q.back()=='.') q.push(s[i]);
            else{
                if(q.back()=='a'||q.back()=='e'){
                    if(s[i+1]=='a'||s[i+1]=='e') q.push('.'),q.push(s[i]);
                    else q.push(s[i]),q.push('.');
                }
                else q.push(s[i]),q.push('.');
            }
        }
    }
    while(!q.empty()) cout<<q.front(),q.pop();
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
