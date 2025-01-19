#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
struct Node{ll id,val;}a[200010];
ll _,n,b[200010];
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
ll cmp(Node x,Node y){return x.val<y.val;}
class Solution{
public:
    void main(){
        read(n);
        for(ll i=1;i<=n;++i) read(a[i].val),a[i].id=i,b[i]=1;
        if(n==2){puts("10");return;}
        sort(a+1,a+1+n,cmp);
        b[a[1].id]=b[a[2].id]=0;
        for(ll i=1;i<=n;++i) write(b[i]);
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    //read(_);
    _=1;
    while(_--){
        solution.main();
    }
    return 0;
}
