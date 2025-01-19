#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
string s,t,st;
map<string,string>f;
string find_set(string x){return f[x]==x?x:f[x]=find_set(f[x]);}
void merge_set(string x,string y){
    string fx=find_set(x);
	if(fx!=y) f[y]=fx;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>s&&s!="$")
        switch(s[0]){
            case '#':{
                t=s.substr(1);
			    if(f.find(t)==f.end()) f[t]=t;
            }
            break;
            case '+':{
			    st=s.substr(1);
			    merge_set(t,st);
		    }
            break;
            case '?':{
			    st=s.substr(1);
			    find_set(st);
			    cout<<st+" "+f[st]+"\n";
		    }
            break;
        }
    return 0;
}