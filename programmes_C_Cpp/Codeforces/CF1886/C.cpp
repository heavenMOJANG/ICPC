#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    string s;cin>>s;
	int n=s.length();
	list<char>l(s.begin(), s.end());
	int pos;cin>>pos;
	auto it=l.begin();	
	for(int i=n;i>=1;--i){
		if(pos<=i){
			auto it=l.begin();
			for(int j=1;j<pos;++j) it++;
			cout<<*it;
			return; 
		}
		int flag=1;
		while(it!=(--l.end())){
			auto nxt=it;
            nxt++;
			if(*it>*nxt){
				l.erase(it);
				if(nxt==l.begin()) it=nxt;
				else it=--nxt;
				flag=0;
				break;
			}
			it++;
		}
		if(flag) l.erase(it--);
		pos-=i;
	}
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
