#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
struct Node{ll num,id;}a[200010];
ll _,n,k,b[200010];
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
	    for(ll i=1,x;i<=n;++i){
		    read(x);
            a[i]={x,i};
            b[i]=x;
	    }
	    sort(a+1,a+1+n,[](const Node&x,const Node&y){return x.num<y.num;});
	    ll minn=LLONG_MAX,p1=1,p2=1;
	    for(ll i=1;i<n;++i){
            ll t=a[i].num^a[i+1].num;
		    if(t<minn){
			    minn=t;
			    p1=a[i].id,p2=a[i+1].id;
		    }
	    }
        if(p1>p2) swap(p1,p2);
	    ll x=0,t=1,c=b[p1],d=b[p2];
	    for(ll i=0;i<k;++i){
		    if(c%2==d%2&&c%2==0) x+=t;
		    t<<=1;
	    	c>>=1;
            d>>=1;
	    }
        write(p1);putchar(' ');
        write(p2);putchar(' ');
        write(x);puts("");
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
