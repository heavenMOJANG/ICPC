#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,b[200010];
map<ll,ll>a;
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
        read(n);
        a.clear();
        memset(b,0,sizeof(b));
        vector<ll>v,w;
        for(ll i=1;i<n;++i) read(b[i]),a[b[i]-b[i-1]]++,w.push_back(b[i]-b[i-1]);
        for(ll i=1;i<=n;++i) if(!a[i]) v.push_back(i);
        if(v.size()==1) puts("YES");
        else if(v.size()==2){
            if(a[v[0]+v[1]]){
                vector<ll>vv;
				ll flag=1;
				for(ll i=0;i<n-1;++i){
					if(w[i]!=v[0]+v[1])
					vv.push_back(w[i]);
					else if(flag) vv.push_back(v[0]),vv.push_back(v[1]),flag=0;
					else vv.push_back(w[i]);
				}
				sort(vv.begin(),vv.end());
				for(ll i=1;i<=n;++i) if(vv[i-1]!=i){puts("NO");return;}
				puts("YES");
            }
            else puts("NO");
        }
        else puts("NO");
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
