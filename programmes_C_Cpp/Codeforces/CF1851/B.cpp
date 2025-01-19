#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,a[200010],b[200010];
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
        ll x=0;
        read(n);
        priority_queue<ll,vector<ll>,greater<ll>>q1,q2;
	    for(ll i=1;i<=n;i++){
		    read(a[i]);
		    if(a[i]&1) q1.push(a[i]);
		    else q2.push(a[i]);
	    }
	    for(ll i=1;i<=n;++i){
		    if(a[i]%2==1){
			    b[++x]=q1.top();
			    q1.pop();
		    }
		    else{
			    b[++x]=q2.top();
			    q2.pop();
		    }
	    }
        for(ll i=2;i<=n;++i){
            if(b[i]<b[i-1]){puts("NO");return;}
        }
        puts("YES");
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
