#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,m,l,r;
char c[200010];
void read(ll&n){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    n=x*f;
}
void write(ll n){
    if(n<0){putchar('-');n*=-1;}
    static ll sta[128];
    ll top=0;
    do{
        sta[top++]=n%10,n/=10;
    }while(n);
    while(top) putchar(sta[--top]+48);
}
class Solution{
public:
    void main(){
        read(n);read(m);
        for(ll i=0;i<n;++i) c[i]=getchar();
        vector<ll>pre(n,-1),suf(n,n);
        set<pair<ll,ll>>s;
        for(ll i=0;i<n;++i){
		    if(i!=0) pre[i]=pre[i-1];
		    if(c[i]=='0') pre[i]=i;
        }
	    for(ll i=n-1;i>=0;--i){
		    if(i!=n-1) suf[i]=suf[i+1];
		    if(c[i]=='1') suf[i]=i;
	    }
        while(m--){
            read(l);read(r);
            l--,r--;
            ll R=pre[r],L=suf[l];
		    if(L>R) s.insert({-1,-1});
            else s.insert({L,R});      
        }
        write(s.size()),puts("");
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
