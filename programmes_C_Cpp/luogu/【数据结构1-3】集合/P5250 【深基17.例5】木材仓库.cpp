#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
set<ll>::iterator lb,it1,it2;
set<ll>s;
ll n;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
	for(ll i=1,op,len;i<=n;++i){
		cin>>op>>len;
		if(op==1){
            if(s.find(len)!=s.end()) cout<<"Already Exist\n";
            else s.insert(len);
        }
		else{
			if(s.empty()){cout<<"Empty\n";continue;}
			if(s.find(len)!=s.end()) cout<<len,s.erase(s.find(len));
			else{
				lb=it1=it2=s.lower_bound(len);
				if(lb==s.begin()) cout<<*lb,s.erase(lb);
				else if(lb==s.end()) cout<<*(--it2),s.erase(it2);
				else if(*lb-len<len-*(--it1)) cout<<*(it2),s.erase(it2);
				else cout<<*(--it2),s.erase(it2);
			}
			cout<<"\n";
		}
	}
    return 0;
}