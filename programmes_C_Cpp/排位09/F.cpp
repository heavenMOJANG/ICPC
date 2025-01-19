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
    vector<int>vis(1010,0);
    if(s.size()==1){cout<<"Case "<<++idx<<": S\n";return;}
    int sum=0;
    for(int i=0;i<s.size();++i) sum+=s[i]-48;
    int flag=0;
	while(1){
		int found=0,minn=-1,p;
		for(int i=0;i<s.size();++i){
			if(!vis[i])
				if((sum-s[i]+48)%3==0){
					found=1;
					if(s[i]-48>minn) minn=s[i]-48,p=i;
				}
		}
		if(!found) break;
		else{
            flag^=1;
            vis[p]=1;
            sum-=s[p]-48;
        }
	}
    cout<<"Case "<<++idx<<": "<<(flag?"S\n":"T\n");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
