#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
struct Node{ll id,hp;}a[300010];
ll _,n,k;
ll cmp(Node x,Node y){return x.hp==y.hp?x.id<y.id:x.hp>y.hp;}
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
        read(n);read(k);
        for(ll i=1,x;i<=n;++i){
		    read(x);
		    x%=k;
	        if(x==0) x=k;
		    a[i]={i,x};
	    }
	    sort(a+1,a+1+n,cmp);
	    for(ll i=1;i<=n;++i) write(a[i].id),putchar(' ');
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
