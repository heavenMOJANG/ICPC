#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,m,k;
void read(ll&n){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    n=x*f;
}
void write(ll n){
    if(n<0){putchar('-');n*=-1;}
    static ll sta[35];
    ll top=0;
    do{
        sta[top++]=n%10,n/=10;
    }while(n);
    while(top) putchar(sta[--top]+48);
}
class Solution{
public:
    void main(){
        read(n);read(k);
	    vector<ll>c(n),p(k);
	    for(ll i=0;i<n;++i) read(c[i]);
	    vector<ll>f(n,0);
	    for(ll i=0;i<k;i++){
		    read(p[i]);
            p[i]--;
            c[p[i]]=0;
            f[p[i]]=1;
        }
	    vector<vector<ll>>v(n);
	    for(ll i=0;i<n;++i){
		    read(m);
		    for(ll j=0,e;j<m;++j){
			    read(e);e--;
			    v[i].emplace_back(e);
		    }
	    }
	    function<void(ll)>cal=[&](ll x){
		    ll res=0;
		    if(v[x].size()==0){f[x]=1;return;}
		    for(auto y:v[x]){
			    if(!f[y])cal(y),res+=c[y];
			    else res+=c[y];
		    }
		    f[x]=1;
		    c[x]=min(c[x],res);
	    };
	    for(ll i=0;i<n;++i){
		    if(!f[i]) cal(i);
		    write(c[i]),putchar(' ');
	    }
        puts("");
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    read(_);
    while(_--){
        solution.main();
    }
    return 0;
}
