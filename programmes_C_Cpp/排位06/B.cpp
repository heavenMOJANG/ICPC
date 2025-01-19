#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int idx;
void solve(){
    string s;cin>>s;
    int n=s.size();
    function<int(void)> check=[&]()->int
    {
        for(int i=0;i<n-2;++i)
            if(s[i]=='X'&&s[i+1]=='X'&&s[i+2]=='X') return 1;
        return 0;
    };
    function<int(int)> crt=[&](int x)->int
    {

    };
    for(int i=0;i<n;++i){
        if(s[i]=='X') continue;
        s[i]='X';
        if(check()||place()) ans[pos++]=i+1;
        s[i]='.';
    }
    if(pos==0) cout<<"Case "<<++idx<<": 0\n";
    else{
        cout<<cout<<"Case "<<++idx<<":";
        for(int i=0;i<pos;++i) cout<<" "<<ans[i];
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
