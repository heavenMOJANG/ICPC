#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
string solve(){
	string res="";
	char ch;
	while(cin>>ch){
		if(ch=='\n') break;
		else if(ch=='['){
			ll x;cin>>x;
			string tmp=solve();
			for (ll i=1;i<=x;++i) res+=tmp;
		}
		else{
            if (ch == ']') return res;
		    else res+=ch;
        }
	}
	return res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<solve();
    return 0;
}