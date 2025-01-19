#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
char ch[100010];
void solve(){
    int n;cin>>n;
    int top=-1,f=0;
    for(int i=0;i<n;++i){
        string s;cin>>s;
        if(s=="Backspace"){
            if(top==-1) continue;
            else top--;
        }
        else if(s=="Space") ch[++top]=' ';
        else if(s=="CapsLock") f^=1;
        else 
            if(!f) ch[++top]=s[0];
            else ch[++top]=s[0]-'a'+'A';
    }
    for(int i=0;i<=top;++i) cout<<ch[i];
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
