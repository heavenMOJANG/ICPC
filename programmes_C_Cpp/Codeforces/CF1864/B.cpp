#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    if(k&1){
        string t[2];
        for(int i=0;i<s.length();++i)t[i%2]+=s[i];
		sort(t[0].begin(),t[0].end());
		sort(t[1].begin(),t[1].end());
		for(int i=0;i<t[0].length();++i){
			cout<<t[0][i];
			if(i<t[1].length()) cout<<t[1][i];
		}
        cout<<"\n";
    }
    else{
        sort(s.begin(),s.end());
        cout<<s<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
